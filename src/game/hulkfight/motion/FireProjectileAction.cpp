// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00199630..0x0019c050 (kind game, layer game, confidence high), dominant class hulkfight::motion::FireProjectileAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f740ace1 {
#define TREE_TU_END }
namespace fn_f740ace1 {} using namespace fn_f740ace1;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f740ace1 {
class RefObj_199630 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_199630 {
  public:
    Action_199630();
    virtual void Update();
    char pad[0x18];
};
class MissilePunchAction_199630 : public Action_199630 {
  public:
    int mTarget;
    RefObj_199630* mObj;
    MissilePunchAction_199630(int target, RefObj_199630* obj);
    virtual void Execute();
};
extern void* hulk_at_0041b51c[];
class Ref_199680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_199680 {
  public:
    void* vptr;
};
class MissilePunchAction_199680 : public Action_199680 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_199680* m20;
    ~MissilePunchAction_199680();
};
class CStageCondition_199700;
class ParamValue_199700 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199700 : public ParamValue_199700 {
  public:
    int pad;
};
class CStageCondition_199750;
class ParamValue_199750 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199750 : public ParamValue_199750 {
  public:
    int pad;
};
class CStageCondition_1997a0;
class ParamValue_1997a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1997a0 : public ParamValue_1997a0 {
  public:
    int pad;
};
class CStageCondition_1997f0;
class ParamValue_1997f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1997f0 : public ParamValue_1997f0 {
  public:
    int pad;
};
class CStageCondition_199840;
class ParamValue_199840 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199840 : public ParamValue_199840 {
  public:
    int pad;
};
class CStageCondition_199890;
class ParamValue_199890 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199890 : public ParamValue_199890 {
  public:
    int pad;
};
class CStageCondition_1998e0;
class ParamValue_1998e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1998e0 : public ParamValue_1998e0 {
  public:
    int pad;
};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
struct CAxisArcCondition_199950;
class CStageCondition_199960 {};
class ParamValue_199960 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_199960 : public ParamValue_199960 {
  public:
    virtual void f();
};
class CStageCondition_1999f0;
class ParamValue_1999f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1999f0 : public ParamValue_1999f0 {
  public:
    int pad;
};
class CStageCondition_199a40;
class ParamValue_199a40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199a40 : public ParamValue_199a40 {
  public:
    int pad;
};
class CStageCondition_199a90;
class ParamValue_199a90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199a90 : public ParamValue_199a90 {
  public:
    int pad;
};
class CStageCondition_199ae0;
class ParamValue_199ae0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199ae0 : public ParamValue_199ae0 {
  public:
    int pad;
};
class CStageCondition_199b60;
class ParamValue_199b60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199b60 : public ParamValue_199b60 {
  public:
    int pad;
};
class CStageCondition_199bb0;
class ParamValue_199bb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199bb0 : public ParamValue_199bb0 {
  public:
    int pad;
};
class CStageCondition_199c00;
class ParamValue_199c00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199c00 : public ParamValue_199c00 {
  public:
    int pad;
};
class CStageCondition_199c50;
class ParamValue_199c50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199c50 : public ParamValue_199c50 {
  public:
    int pad;
};
class CStageCondition_199ca0;
class ParamValue_199ca0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199ca0 : public ParamValue_199ca0 {
  public:
    int pad;
};
struct CAxisArcCondition_199d10;
class CStageCondition_199d20 {};
class ParamValue_199d20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_199d20 : public ParamValue_199d20 {
  public:
    virtual void f();
};
class CStageCondition_199db0;
class ParamValue_199db0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199db0 : public ParamValue_199db0 {
  public:
    int pad;
};
class CStageCondition_199e00;
class ParamValue_199e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199e00 : public ParamValue_199e00 {
  public:
    int pad;
};
class CStageCondition_199e50;
class ParamValue_199e50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199e50 : public ParamValue_199e50 {
  public:
    int pad;
};
class CStageCondition_199ea0;
class ParamValue_199ea0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199ea0 : public ParamValue_199ea0 {
  public:
    int pad;
};
class CStageCondition_199f20;
class ParamValue_199f20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_199f20 : public ParamValue_199f20 {
  public:
    int pad;
};
struct CAxisArcCondition_199f60;
class CStageCondition_199f70 {};
class ParamValue_199f70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_199f70 : public ParamValue_199f70 {
  public:
    virtual void f();
};
class CStageCondition_19a000;
class ParamValue_19a000 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_19a000 : public ParamValue_19a000 {
  public:
    int pad;
};
class CStageCondition_19a050;
class ParamValue_19a050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_19a050 : public ParamValue_19a050 {
  public:
    int pad;
};
class CStageCondition_19a0a0;
class ParamValue_19a0a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_19a0a0 : public ParamValue_19a0a0 {
  public:
    int pad;
};
struct CAxisArcCondition_19a0e0;
class CStageCondition_19a0f0 {};
class ParamValue_19a0f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_19a0f0 : public ParamValue_19a0f0 {
  public:
    virtual void f();
};
extern char DAT_004c0b38;
} // namespace fn_f740ace1
namespace fight {
class ConditionFactoryCaster_19a180 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropGrabbableIsMissileCondition_19a180 {};
} }
namespace fn_f740ace1 {
class Base {
  public:
    virtual int Test(void*);
    virtual void v1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004c0c00;
extern char DAT_0049850c;
extern char DAT_004c0cc0;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a260 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace motion {
class FireProjectileTrack_19a260 {};
} }
namespace fn_f740ace1 {
extern char DAT_004c0d70;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a360 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class MissileThrowTrack_19a360;
} }
namespace fn_f740ace1 {
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_004c0e20;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a400 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class MissilePunchTrack_19a400 {};
} }
namespace fn_f740ace1 {
extern char DAT_004c0ed8;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a480 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class AccuracyLatencyTrack_19a480 {};
} }
namespace fight {
class TrackFactoryCaster_19a4e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FireBeamTrack_19a4e0 {};
} }
namespace fn_f740ace1 {
extern char DAT_004c0f88;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a5e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FireMissileTrack_19a5e0 {};
} }
namespace fn_f740ace1 {
extern char DAT_004c1030;
extern char DAT_004c10e0;
} // namespace fn_f740ace1
namespace fight {
class TrackFactoryCaster_19a700 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FireGroundShockwaveTrack_19a700 {};
} }
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f740ace1 {
void* FUN_0008d690(unsigned int size);
} // namespace fn_f740ace1
namespace hulkfight { namespace motion {
class PropGrabbableIsMissileCondition_19a7d0 {
public:
    void FUN_00192160();
};
} }
namespace fn_f740ace1 {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_f740ace1
namespace fight {
template <class T>
class ParamBool_19a7d0 : public ParamBoolBase {
public:
    ParamBool_19a7d0(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f740ace1 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_f740ace1
namespace hulkfight { namespace motion {
class PropIsMissileCondition_19a830 {
public:
    void FUN_00192170();
    void FUN_00192180();
};
} }
namespace fight {
template <class T>
class ParamBool_19a830 : public ParamBoolBase {
public:
    ParamBool_19a830(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_19a830 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19a830(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f740ace1 {
class MissileThrowTrack {
public:
    void FUN_00192570();
    void FUN_00192590();
    void FUN_001925c0();
    void FUN_001925f0();
    void FUN_00192610();
    void FUN_00192630();
    void FUN_00192650();
    void FUN_00192670();
    void FUN_001926a0();
    void FUN_001926d0();
    void FUN_00192700();
    void FUN_00192730();
    void FUN_00192760();
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f740ace1
namespace fight {
template <class T>
class ParamFloatConstRange_19a8d0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_19a8d0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_19a8d0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_19a8d0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_19a8d0 : public ParamVectorBase {
public:
    ParamVector_19a8d0(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f740ace1 {
typedef unsigned int u32_19ada0;
extern int hulk_at_00494b44, hulk_at_00494b60;
struct Params_19ada0 {
    int Init_00195100(hulkfight::motion::FireProjectileTrack*, void*);
};
extern void* Alloc(hulk_uintptr);
extern void* hulk_at_0041b3d8[];
class Ref_19adf0 {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
};
class Action_19adf0 {
  public:
    void* vptr;
};
void Free_0008d330(void*) throw();
class FireProjectileAction_19adf0 : public Action_19adf0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_19adf0* m20;
    char p[4];
    Ref_19adf0* m28;
    Ref_19adf0* m2c;
    FireProjectileAction_19adf0* f2(unsigned char fl);
};
struct V3_19ae50 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(V3_19ae50 *other, float limit);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_19ae50 *axis, float angle);
};
class Refd_19ae50 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Pool_19ae50 {
    int FUN_001b6b00(int id, V3_19ae50 *a);
    void FUN_001b6d00(int id, class ProjectileEffect_19ae50 *p);
};
} // namespace fn_f740ace1
struct World {
    char pad0[0x14];
    Pool_19ae50 *pool;
};
namespace fn_f740ace1 {
struct Allocator {
};
struct Cfg_19ae50 {
    char pad0[0x2c];
    float f2c;
    char pad30[0x40 - 0x30];
    V3_19ae50 v40;
    V3_19ae50 v4c;
    float f58;
    float f5c;
    char pad60[0x68 - 0x60];
    int f68;
    int f6c;
    char pad70[0x74 - 0x70];
    char b74;
    char pad75[7];
    int f7c;
};
class ProjectileEffect_19ae50 : public Refd_19ae50 {
public:
    char pad04[0x14 - 4];
    int f14;
    char pad18[0x20 - 0x18];
    void *f20;
    Refd_19ae50 *f24;
    V3_19ae50 f28;
    V3_19ae50 f34;
    V3_19ae50 f40;
    float f4c;
    ProjectileEffect_19ae50 *FUN_00195a90(Cfg_19ae50 *cfg);
};
struct Target_19ae50 : Refd_19ae50 {
};
struct Ctx_19ae50;
struct Stats_19ae50 {
    char pad0[0x328];
    Target_19ae50 *target;
    Target_19ae50 *FUN_00039c60(V3_19ae50 *a, V3_19ae50 *b, int lo, int hi, int z1, int z2, int z3);
};
struct Ctx_19ae50 {
    Stats_19ae50 *FUN_00059a30();
    char FUN_00059a50(V3_19ae50 *out);
};
struct OwnerObj_19ae50 {
    char pad0[8];
    void *f8;
};
struct Rng_19ae50 {
    hulk_freg FUN_000787e0(int lo, int hi);
};
extern "C" Rng_19ae50 *FUN_000964d0();
class Weapon_19ae50 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void *v15();
};
struct Ctrl_19ae50 {
    char pad0[0x1c];
    char *mats;
};
char __cdecl FUN_00096b50(Target_19ae50 *t, V3_19ae50 *c, void *out);
union Slot_19ae50 {
    int i;
    float f;
    unsigned int u;
};
class FireProjectileAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(int a1, Slot_19ae50 a2);
    char pad04[0x18];
    Cfg_19ae50 *cfg;
    OwnerObj_19ae50 *owner;
    float f24;
    Weapon_19ae50 *f28;
    Ctrl_19ae50 *f2c;
    int f30;
};
extern "C" char DAT_0041b3f4[];
class H {
  public:
    void Fn_0027ffb0(int);
};
class ProjectileEffect {
  public:
    virtual void A();
    virtual void B();
    virtual ProjectileEffect* vfunc_2(unsigned char);
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad0[0x14];
    int m18;
    int m1c;
    char pad20[4];
    class Obj {
      public:
        virtual void A();
        virtual void B();
    };
    Obj* m24;
    void Cleanup_001b6820();
};
class Global_19b350 {
  public:
    void Free_0008ff00(void*, int);
};
extern H* __cdecl FUN_0027f250();
extern Global_19b350* g_19b350;
class Params_19b3c0 {
  public:
    int x;
};
extern Params_19b3c0 TypeA_19b3c0;
extern Params_19b3c0 TypeB_19b3c0;
class Object_19b3c0 {
  public:
    int Init_00196220(hulkfight::motion::FireMissileTrack*, hulk_intptr);
};
Object_19b3c0* __cdecl Alloc_0008d690(int);
struct RefCounted_19b410 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041b414[];
class FireMissileAction_19b410 {
  public:
    FireMissileAction_19b410* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_19b410* m_20;
};
struct Vec3_19b5f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mat_19b5f0 {
    float m[16];
};
struct RefObj_19b5f0 {
    virtual void AddRef();
    virtual void Release();
};
struct Beam_19b5f0 : RefObj_19b5f0 {
    char pad04[0x3c];
    Vec3_19b5f0 pos;
};
struct Fighter_19b5f0 {
    char pad0[0x328];
    Beam_19b5f0* beam;
    Beam_19b5f0* FUN_00039c60(Vec3_19b5f0* origin, Vec3_19b5f0* dir, int a, int b, int c, int d, int e);
};
struct Skeleton {
    char pad0[0x1c];
    Mat_19b5f0* mats;
};
struct MatSource_19b5f0 {
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
    virtual Mat_19b5f0* vfunc_15();
};
struct Config_19b5f0 {
    char pad0[8];
    int f8;
    char pad0c[0x38 - 0xc];
    Vec3_19b5f0 v38;
    Vec3_19b5f0 v44;
    float f50;
    int f54;
    int f58;
    char pad5c[4];
    char f60;
};
struct Owner_19b5f0 {
    char pad0[8];
    int f8;
};
struct BeamState {
    char pad0[0x10];
    int f10;
    Beam_19b5f0* ref;
    Vec3_19b5f0 origin;
    Vec3_19b5f0 dir;
    float f30;
    void FUN_00197ff0(float dt);
};
void* __fastcall FUN_000592a0(Owner_19b5f0* owner);
extern "C" Fighter_19b5f0* __fastcall FUN_00059a30(void* x);
char __cdecl FUN_00096b50(Beam_19b5f0* e, Vec3_19b5f0* io, int* out);
class FireBeamAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int phase, float dt);
    char pad04[0x18];
    Config_19b5f0* cfg;
    Owner_19b5f0* owner;
    char pad24[0x30 - 0x24];
    float time;
    MatSource_19b5f0* source;
    Skeleton* skeleton;
    int jointIndex;
    char pad40[0x60 - 0x40];
    Beam_19b5f0* beam;
    char pad64[4];
    BeamState* state;
    void FUN_00197610(float dt);
};
extern void* hulk_at_0041b4a0[];
class Ref_19b830 {
  public:
    virtual void F0();
    virtual void Release();
};
class BeamEffect_19b830 {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
    Ref_19b830* m14;
    BeamEffect_19b830* f2(unsigned char flags);
};
typedef unsigned int u32_19b870;
extern int TypeA_19b870, hulk_at_00494b60;
struct Params_19b870 {
    int Init_001984c0(hulkfight::motion::AccuracyLatencyTrack*, void*);
};
struct RefCounted_19b8c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041b4a8[];
class AccuracyLatencyAction_19b8c0 {
  public:
    AccuracyLatencyAction_19b8c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_19b8c0* m_20;
};
struct RefCounted_19b960 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041b4c4[];
class MissileThrowAction_19b960 {
  public:
    MissileThrowAction_19b960* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_19b960* m_20;
};
struct RefCounted_19ba00 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0041b4e0[];
class FireGroundShockwaveAction_19ba00 {
  public:
    FireGroundShockwaveAction_19ba00* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_19ba00* m_20;
};
struct RefCounted_19bc50 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_19bc50[];
class MissilePunchAction_19bc50 {
  public:
    MissilePunchAction_19bc50* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_19bc50* m_20;
};


// 0x00199630 FUN_00199630 (72 B): matches/0x00199630.cpp
// sym: ??0MissilePunchAction_199630@fn_f740ace1@@QAE@HPAVRefObj_199630@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
MissilePunchAction_199630::MissilePunchAction_199630(int target, RefObj_199630* obj) {
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


// 0x00199680 FUN_00199680 (50 B): matches/0x00199680.cpp
// sym: ??1MissilePunchAction_199680@fn_f740ace1@@QAE@XZ
MissilePunchAction_199680::~MissilePunchAction_199680() {
    vptr = hulk_at_0041b51c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_199680 *)this)->FUN_002326a0();
}

} // namespace fn_f740ace1

// 0x001996e0 fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_6 (26 B): matches/0x001996e0.cpp
// sym: ?vfunc_6@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::**)(int))&this->f_10))(b);
}


// 0x00199700 fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_2 (11 B): matches/0x00199700.cpp
// sym: ?vfunc_2@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199730 fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::vfunc_6 (26 B): matches/0x00199730.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::**)(int))&this->f_10))(b);
}


// 0x00199750 fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::vfunc_2 (11 B): matches/0x00199750.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199780 fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::vfunc_6 (26 B): matches/0x00199780.cpp
// sym: ?vfunc_6@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::PropIsMissileCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::**)(int))&this->f_10))(b);
}


// 0x001997a0 fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::vfunc_2 (11 B): matches/0x001997a0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001997d0 fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_6 (26 B): matches/0x001997d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))(b);
}


// 0x001997f0 fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_2 (11 B): matches/0x001997f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199820 fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_6 (26 B): matches/0x00199820.cpp
// sym: ?vfunc_6@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FireProjectileTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199840 fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_2 (11 B): matches/0x00199840.cpp
// sym: ?vfunc_2@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199870 fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_6 (26 B): matches/0x00199870.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199890 fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_2 (11 B): matches/0x00199890.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001998c0 fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_6 (26 B): matches/0x001998c0.cpp
// sym: ?vfunc_6@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FireProjectileTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_10))(b);
}


// 0x001998e0 fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_2 (11 B): matches/0x001998e0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f740ace1 {

// 0x00199910 fight::ParamBranch<hulkfight::motion::FireProjectileTrack>::vfunc_6 (12 B): matches/0x00199910.cpp
// sym: ?vfunc_6@ParamBranch@fn_f740ace1@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f740ace1

// 0x00199950 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_7 (6 B): matches/0x00199950.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00199960 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_6 (30 B): matches/0x00199960.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_199960 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_199960*)&DAT_003f335c));
}


// 0x00199980 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_8 (26 B): matches/0x00199980.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::**)(int))&this->f_18))(b);
}


// 0x001999a0 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_2 (11 B): matches/0x001999a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001999d0 fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_6 (26 B): matches/0x001999d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x001999f0 fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_2 (11 B): matches/0x001999f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199a20 fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_6 (26 B): matches/0x00199a20.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00199a40 fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_2 (11 B): matches/0x00199a40.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199a70 fight::ParamVector<hulkfight::motion::MissileThrowTrack>::vfunc_6 (26 B): matches/0x00199a70.cpp
// sym: ?vfunc_6@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::MissileThrowTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::MissileThrowTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::MissileThrowTrack>::**)(int))&this->f_10))(b);
}


// 0x00199a90 fight::ParamVector<hulkfight::motion::MissileThrowTrack>::vfunc_2 (11 B): matches/0x00199a90.cpp
// sym: ?vfunc_2@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::MissileThrowTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199ac0 fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::vfunc_6 (26 B): matches/0x00199ac0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::**)(int))&this->f_10))(b);
}


// 0x00199ae0 fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::vfunc_2 (11 B): matches/0x00199ae0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199b10 fight::ParamBranch<hulkfight::motion::MissilePunchTrack>::vfunc_6 (12 B): matches/0x00199b10.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00199b10@@UAEXPAX@Z
namespace fn_00199b10 {
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
} // namespace fn_00199b10


// 0x00199b40 fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::vfunc_6 (26 B): matches/0x00199b40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::**)(int))&this->f_10))(b);
}


// 0x00199b60 fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::vfunc_2 (11 B): matches/0x00199b60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199b90 fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_6 (26 B): matches/0x00199b90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))(b);
}


// 0x00199bb0 fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_2 (11 B): matches/0x00199bb0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199be0 fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_6 (26 B): matches/0x00199be0.cpp
// sym: ?vfunc_6@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FireBeamTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))(b);
}


// 0x00199c00 fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_2 (11 B): matches/0x00199c00.cpp
// sym: ?vfunc_2@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199c30 fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_6 (26 B): matches/0x00199c30.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))(b);
}


// 0x00199c50 fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_2 (11 B): matches/0x00199c50.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199c80 fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_6 (26 B): matches/0x00199c80.cpp
// sym: ?vfunc_6@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FireBeamTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_10))(b);
}


// 0x00199ca0 fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_2 (11 B): matches/0x00199ca0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199cd0 fight::ParamBranch<hulkfight::motion::FireBeamTrack>::vfunc_6 (12 B): matches/0x00199cd0.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00199cd0@@UAEXPAX@Z
namespace fn_00199cd0 {
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
} // namespace fn_00199cd0


// 0x00199d10 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_7 (6 B): matches/0x00199d10.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00199d20 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_6 (30 B): matches/0x00199d20.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_199d20 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_199d20*)&DAT_003f335c));
}


// 0x00199d40 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_8 (26 B): matches/0x00199d40.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::**)(int))&this->f_18))(b);
}


// 0x00199d60 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_2 (11 B): matches/0x00199d60.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00199d90 fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_6 (26 B): matches/0x00199d90.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199db0 fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199db0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199de0 fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_6 (26 B): matches/0x00199de0.cpp
// sym: ?vfunc_6@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FireMissileTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199e00 fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199e00.cpp
// sym: ?vfunc_2@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199e30 fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_6 (26 B): matches/0x00199e30.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199e50 fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199e50.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199e80 fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_6 (26 B): matches/0x00199e80.cpp
// sym: ?vfunc_6@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FireMissileTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199ea0 fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199ea0.cpp
// sym: ?vfunc_2@?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199ed0 fight::ParamBranch<hulkfight::motion::FireMissileTrack>::vfunc_6 (12 B): matches/0x00199ed0.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00199ed0@@UAEXPAX@Z
namespace fn_00199ed0 {
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
} // namespace fn_00199ed0


// 0x00199f00 fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_6 (26 B): matches/0x00199f00.cpp
// sym: ?vfunc_6@?$ParamString@VFireMissileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::motion::FireMissileTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_10))(b);
}


// 0x00199f20 fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199f20.cpp
// sym: ?vfunc_2@?$ParamString@VFireMissileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00199f60 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_7 (6 B): matches/0x00199f60.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00199f70 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_6 (30 B): matches/0x00199f70.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_199f70 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_199f70*)&DAT_003f335c));
}


// 0x00199f90 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_8 (26 B): matches/0x00199f90.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::**)(int))&this->f_18))(b);
}


// 0x00199fb0 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_2 (11 B): matches/0x00199fb0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00199fe0 fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6 (26 B): matches/0x00199fe0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))(b);
}


// 0x0019a000 fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2 (11 B): matches/0x0019a000.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0019a030 fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6 (26 B): matches/0x0019a030.cpp
// sym: ?vfunc_6@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))(b);
}


// 0x0019a050 fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2 (11 B): matches/0x0019a050.cpp
// sym: ?vfunc_2@?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0019a080 fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6 (26 B): matches/0x0019a080.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_10))(b);
}


// 0x0019a0a0 fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2 (11 B): matches/0x0019a0a0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0019a0e0 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_7 (6 B): matches/0x0019a0e0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x0019a0f0 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6 (30 B): matches/0x0019a0f0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_19a0f0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_19a0f0*)&DAT_003f335c));
}


// 0x0019a110 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_8 (26 B): matches/0x0019a110.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::**)(int))&this->f_18))(b);
}


// 0x0019a130 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2 (11 B): matches/0x0019a130.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x0019a160 fight::ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_6 (12 B): matches/0x0019a160.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019a160@@UAEXPAX@Z
namespace fn_0019a160 {
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
} // namespace fn_0019a160


// 0x0019a180 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_0 (36 B): matches/0x0019a180.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004c0b38, 0) != 0;
}


// 0x0019a1b0 fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_0 (30 B): matches/0x0019a1b0.cpp
// sym: ??_G?$ParamBool@VPropGrabbableIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropGrabbableIsMissileCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a1b0)
#endif


// 0x0019a1e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_0 (36 B): matches/0x0019a1e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c0c00, 0) != 0;
}


// 0x0019a210 fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::vfunc_0 (30 B): matches/0x0019a210.cpp
// sym: ??_G?$ParamIntConstRange@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::PropIsMissileCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a210)
#endif


// 0x0019a230 fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::vfunc_0 (30 B): matches/0x0019a230.cpp
// sym: ??_G?$ParamBool@VPropIsMissileCondition@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::PropIsMissileCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::PropIsMissileCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a230)
#endif


// 0x0019a260 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_0 (36 B): matches/0x0019a260.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFireProjectileTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004c0cc0, 0)) != 0;
}


// 0x0019a290 fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a290.cpp
// sym: ??_G?$ParamFloatConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a290)
#endif


// 0x0019a2b0 fight::ParamVector<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2b0.cpp
// sym: ??_G?$ParamVector@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::FireProjectileTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a2b0)
#endif


// 0x0019a2d0 fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2d0.cpp
// sym: ??_G?$ParamIntConstRange@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a2d0)
#endif


// 0x0019a2f0 fight::ParamBool<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a2f0.cpp
// sym: ??_G?$ParamBool@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::FireProjectileTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a2f0)
#endif


// 0x0019a310 fight::ParamBranch<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a310.cpp
// sym: ??_G?$ParamBranch@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::FireProjectileTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a310)
#endif


// 0x0019a330 fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019a330.cpp
// sym: ??_G?$ParamEnumConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a330)
#endif


// 0x0019a360 fight::TrackFactoryCasterTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_0 (36 B): matches/0x0019a360.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMissileThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MissileThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c0d70, 0) != 0;
}


// 0x0019a390 fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_0 (30 B): matches/0x0019a390.cpp
// sym: ??_G?$ParamFloatConstRange@VMissileThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::MissileThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a390)
#endif


// 0x0019a3b0 fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::vfunc_0 (30 B): matches/0x0019a3b0.cpp
// sym: ??_G?$ParamIntConstRange@VMissileThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::MissileThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a3b0)
#endif


// 0x0019a3d0 fight::ParamVector<hulkfight::motion::MissileThrowTrack>::vfunc_0 (30 B): matches/0x0019a3d0.cpp
// sym: ??_G?$ParamVector@VMissileThrowTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::MissileThrowTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::MissileThrowTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a3d0)
#endif


// 0x0019a400 fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_0 (36 B): matches/0x0019a400.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMissilePunchTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004c0e20, 0) != 0;
}


// 0x0019a430 fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::vfunc_0 (30 B): matches/0x0019a430.cpp
// sym: ??_G?$ParamFloatConstRange@VMissilePunchTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::MissilePunchTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a430)
#endif


// 0x0019a450 fight::ParamBranch<hulkfight::motion::MissilePunchTrack>::vfunc_0 (30 B): matches/0x0019a450.cpp
// sym: ??_G?$ParamBranch@VMissilePunchTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::MissilePunchTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::MissilePunchTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a450)
#endif


// 0x0019a480 fight::TrackFactoryCasterTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_0 (36 B): matches/0x0019a480.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAccuracyLatencyTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c0ed8, 0) != 0;
}


// 0x0019a4b0 fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::vfunc_0 (30 B): matches/0x0019a4b0.cpp
// sym: ??_G?$ParamFloatConstRange@VAccuracyLatencyTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::AccuracyLatencyTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a4b0)
#endif


// 0x0019a4e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireBeamTrack>::vfunc_0 (36 B): matches/0x0019a4e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFireBeamTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireBeamTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c0f88, 0) != 0;
}


// 0x0019a510 fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a510.cpp
// sym: ??_G?$ParamFloatConstRange@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a510)
#endif


// 0x0019a530 fight::ParamVector<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a530.cpp
// sym: ??_G?$ParamVector@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::FireBeamTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a530)
#endif


// 0x0019a550 fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a550.cpp
// sym: ??_G?$ParamIntConstRange@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a550)
#endif


// 0x0019a570 fight::ParamBool<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a570.cpp
// sym: ??_G?$ParamBool@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::FireBeamTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a570)
#endif


// 0x0019a590 fight::ParamBranch<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a590.cpp
// sym: ??_G?$ParamBranch@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::FireBeamTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a590)
#endif


// 0x0019a5b0 fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019a5b0.cpp
// sym: ??_G?$ParamEnumConstList@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a5b0)
#endif


// 0x0019a5e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_0 (36 B): matches/0x0019a5e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFireMissileTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004c1030, 0)) != 0;
}


// 0x0019a610 fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a610.cpp
// sym: ??_G?$ParamFloatConstRange@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a610)
#endif


// 0x0019a630 fight::ParamVector<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a630.cpp
// sym: ??_G?$ParamVector@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::FireMissileTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a630)
#endif


// 0x0019a650 fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a650.cpp
// sym: ??_G?$ParamIntConstRange@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a650)
#endif


// 0x0019a670 fight::ParamBool<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a670.cpp
// sym: ??_G?$ParamBool@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::motion::FireMissileTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a670)
#endif


// 0x0019a690 fight::ParamBranch<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a690.cpp
// sym: ??_G?$ParamBranch@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::FireMissileTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a690)
#endif


// 0x0019a6b0 fight::ParamString<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a6b0.cpp
// sym: ??_G?$ParamString@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::motion::FireMissileTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a6b0)
#endif


// 0x0019a6d0 fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019a6d0.cpp
// sym: ??_G?$ParamEnumConstList@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a6d0)
#endif


// 0x0019a700 fight::TrackFactoryCasterTemplate<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (36 B): matches/0x0019a700.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c10e0, 0) != 0;
}


// 0x0019a730 fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a730.cpp
// sym: ??_G?$ParamFloatConstRange@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a730)
#endif


// 0x0019a750 fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a750.cpp
// sym: ??_G?$ParamVector@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a750)
#endif


// 0x0019a770 fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a770.cpp
// sym: ??_G?$ParamIntConstRange@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a770)
#endif


// 0x0019a790 fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a790.cpp
// sym: ??_G?$ParamEnumConstList@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a790)
#endif


// 0x0019a7b0 fight::ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019a7b0.cpp
// sym: ??_G?$ParamBranch@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19a7b0)
#endif

namespace fn_f740ace1 {

// 0x0019a7d0 FUN_0019a7d0 (95 B): equivalent/0x0019a7d0.cpp
// sym: ?FUN_0019a7d0@fn_f740ace1@@YAXXZ @329726558796 @w36316c2a142c
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_0019a7d0 @ 0x0019a7d0
void FUN_0019a7d0()
{
    if (DAT_004e154c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19a7d0<hulkfight::motion::PropGrabbableIsMissileCondition_19a7d0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_19a7d0<hulkfight::motion::PropGrabbableIsMissileCondition_19a7d0>("isMissile", &hulkfight::motion::PropGrabbableIsMissileCondition_19a7d0::FUN_00192160);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1548), params, 1);
    }
    DAT_004e154c++;
}


// 0x0019a830 FUN_0019a830 (158 B): equivalent/0x0019a830.cpp
// sym: ?FUN_0019a830@fn_f740ace1@@YAXXZ @1fe0dbb236ac @w403ce37f914a
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0019a830 @ 0x0019a830
void FUN_0019a830()
{
    if (DAT_004e1554 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19a830<hulkfight::motion::PropIsMissileCondition_19a830>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamIntConstRange_19a830<hulkfight::motion::PropIsMissileCondition_19a830>("attachmentIndex", &hulkfight::motion::PropIsMissileCondition_19a830::FUN_00192170);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_19a830<hulkfight::motion::PropIsMissileCondition_19a830>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamBool_19a830<hulkfight::motion::PropIsMissileCondition_19a830>("isMissile", &hulkfight::motion::PropIsMissileCondition_19a830::FUN_00192180);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1550), params, 2);
    }
    DAT_004e1554++;
}


// 0x0019a8d0 FUN_0019a8d0 (715 B): equivalent/0x0019a8d0.cpp
// sym: ?FUN_0019a8d0@fn_f740ace1@@YAXXZ @a8866d950226 @w42e3a475c57a
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 28/28)
// FUN_0019a8d0 @ 0x0019a8d0
void FUN_0019a8d0()
{
    if (DAT_004e1564 == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("timeBegin", &MissileThrowTrack::FUN_00192570);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_19a8d0<MissileThrowTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_19a8d0<MissileThrowTrack>("attachmentIndex", &MissileThrowTrack::FUN_00192590);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_19a8d0<MissileThrowTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector_19a8d0<MissileThrowTrack>("direction", &MissileThrowTrack::FUN_001925c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("distanceMin", &MissileThrowTrack::FUN_001925f0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("distanceMax", &MissileThrowTrack::FUN_00192610);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("velocityMin", &MissileThrowTrack::FUN_00192630);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("velocityMax", &MissileThrowTrack::FUN_00192650);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("spinMin", &MissileThrowTrack::FUN_00192670);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("spinMax", &MissileThrowTrack::FUN_001926a0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("trackingMin", &MissileThrowTrack::FUN_001926d0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("trackingMax", &MissileThrowTrack::FUN_00192700);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("yFixupAngle", &MissileThrowTrack::FUN_00192730);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>));
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamFloatConstRange_19a8d0<MissileThrowTrack>("reigniteCharge", &MissileThrowTrack::FUN_00192760);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1560), params, 13);
    }
    DAT_004e1564++;
}

} // namespace fn_f740ace1

// 0x0019ada0 hulkfight::motion::FireProjectileTrack::vfunc_10 (70 B): matches/0x0019ada0.cpp
// sym: ?vfunc_10@FireProjectileTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireProjectileTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_19ada0 a = (u32_19ada0)__p0; u32_19ada0 b = (u32_19ada0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        Params_19ada0* q = (Params_19ada0*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_00195100(this, p);
    }
    return 0;
}

namespace fn_f740ace1 {

// 0x0019adf0 hulkfight::motion::FireProjectileAction::vfunc_2 (95 B): matches/0x0019adf0.cpp
// sym: ?f2@FireProjectileAction_19adf0@fn_f740ace1@@QAEPAV12@E@Z
FireProjectileAction_19adf0* FireProjectileAction_19adf0::f2(unsigned char fl) {
    vptr = hulk_at_0041b3d8;
    _ReadWriteBarrier();
    if (m2c) {
        m2c->Release();
        m2c = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_19adf0 *)this)->FUN_002326a0();
    if (fl & 1)
        Free_0008d330(this);
    return this;
}


// 0x0019ae50 hulkfight::motion::FireProjectileAction::vfunc_5 (1265 B): equivalent/0x0019ae50.cpp
// sym: ?vfunc_5@FireProjectileAction@fn_f740ace1@@UAE_NHTSlot_19ae50@2@@Z @0593e2a13163 @w734298ae63c9
// STATUS: equivalent (tools/equiv.py level 3: 19992 inputs, branch coverage 32/32)
// hulkfight::motion::FireProjectileAction::vfunc_5 @ 0x0019ae50
bool FireProjectileAction::vfunc_5(int a1, Slot_19ae50 a2)
{
    struct Frame {
        V3_19ae50 b;
        V3_19ae50 a;
        float period;
        float r1;
        V3_19ae50 bm;
        Pool_19ae50 *pool;
        V3_19ae50 P;
        V3_19ae50 c;
        int s48;
        int s4c;
        Stats_19ae50 *fighter;
        float r2;
        Ctx_19ae50 *ctx;
        V3_19ae50 tmp;
        V3_19ae50 zv;
        V3_19ae50 tmp3;
        V3_19ae50 tmp2;
        int out;
        V3_19ae50 v;
        Matrix M;
        Matrix M2;
        Matrix M3;
    } f;

    if (a1 != 1)
        return true;
    f.pool = DAT_004dd700->pool;
    f.ctx = ((Ctx_19ae50 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    f.fighter = f.ctx->FUN_00059a30();
    double sum = (double)a2.f + f24;
    f24 = (float)sum;
    Cfg_19ae50 *c0 = cfg;
    if (c0->f2c > 0.0f)
        f.period = (float)(1.0 / c0->f2c);
    else
        f.period = a2.f;
    if (!(sum > f.period))
        return true;

    do {
        Ctrl_19ae50 *ctrl = f2c;
        f24 = (float)((double)f24 - f.period);
        f.a.z = 0.0f;
        f.a.y = 0.0f;
        f.a.x = 0.0f;
        f.b.x = 0.0f;
        f.b.y = 0.0f;
        f.b.z = -1.0f;
        if (ctrl != 0) {
            int idx6 = f30 << 6;
            Weapon_19ae50 *w = f28;
            if (w != 0) {
                const Matrix *src = (const Matrix *)(ctrl->mats + idx6);
                ((owners::Matrix_22ca90 *)&(f.M))->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix *)src, (const owners::Matrix_22ca90 *)(w->v15()));
            } else {
                memcpy(&f.M, ctrl->mats + idx6, sizeof(Matrix));
            }
            f.tmp = cfg->v40;
            ((owners::Mat_22c2b0 *)&(f.M))->FUN_0022c2b0((float *)(const V3_19ae50 *)(&f.tmp), (float *)(V3_19ae50 *)(&f.a));
            f.tmp2 = cfg->v4c;
            ((owners::M_22c3b0 *)&(f.M))->FUN_0022c3b0((float *)(const V3_19ae50 *)(&f.tmp2), (float *)(V3_19ae50 *)(&f.b));
            f.b.FUN_0022d110();
        }
        int id = cfg->f7c;
        int slot = f.pool->FUN_001b6b00(id, &f.a);
        if (slot >= 0) {
            void *mem = ((void *)((owners::BitPool_8fe90 *)&((*(Allocator*)&DAT_004e2210)))->FUN_0008fe90(0x50));
            ProjectileEffect_19ae50 *proj;
            if (mem)
                proj = ((ProjectileEffect_19ae50 *)mem)->FUN_00195a90(cfg);
            else
                proj = 0;
            proj->AddRef();
            proj->f20 = owner->f8;
            proj->f14 = id;
            Target_19ae50 *tgt = f.fighter->target;
            if (tgt == 0) {
                Cfg_19ae50 *c1 = cfg;
                tgt = f.fighter->FUN_00039c60(&f.a, &f.b, c1->f68, c1->f6c, 0, 0, 0);
                if (tgt != 0)
                    tgt->AddRef();
            } else {
                tgt->AddRef();
            }
            if (proj->f24 != 0)
                proj->f24->Release();
            proj->f24 = tgt;
            if (tgt != 0) {
                if (cfg->b74) {
                    if (FUN_00096b50(tgt, &f.tmp3, &f.out)) {
                        f.b.x = f.tmp3.x - f.a.x;
                        f.b.y = f.tmp3.y - f.a.y;
                        f.b.z = f.tmp3.z - f.a.z;
                        f.b.FUN_0022d110();
                    }
                }
            }
            Cfg_19ae50 *c3 = cfg;
            f.r1 = c3->f58;
            if (f.r1 > 0.0f) {
                Rng_19ae50 *rng = FUN_000964d0();
                f.r1 = rng->FUN_000787e0(0, *(int *)&f.r1);
                f.r2 = rng->FUN_000787e0(0, 0x40c90fdb);
                f.zv.x = 0.0f;
                f.zv.y = 1.0f;
                f.zv.z = 0.0f;
                if (f.b.FUN_0022d2b0(&f.zv, 1e-5f)) {
                    f.c.x = (float)((double)(f.b.y * -1.0f) - (double)(f.b.z * 0.0f));
                    f.c.y = (float)((double)(f.b.z * 0.0f) - (double)(f.b.x * -1.0f));
                    f.c.z = (float)((double)(f.b.x * 0.0f) - (double)(f.b.y * 0.0f));
                } else {
                    f.c.x = (float)((double)(f.b.y * 0.0f) - (double)f.b.z);
                    f.c.y = (float)((double)(f.b.z * 0.0f) - (double)(f.b.x * 0.0f));
                    f.c.z = (float)((double)f.b.x - (double)(f.b.y * 0.0f));
                }
                f.M2.FUN_0022b980();
                f.M2.FUN_0022baf0(&f.c, f.r1);
                f.M3.FUN_0022b980();
                f.M3.FUN_0022baf0(&f.b, f.r2);
                ((owners::M_22c3b0 *)&(f.M2))->FUN_0022c3b0((float *)(const V3_19ae50 *)(&f.b), (float *)(V3_19ae50 *)(&f.v));
                ((owners::M_22c3b0 *)&(f.M3))->FUN_0022c3b0((float *)(const V3_19ae50 *)(&f.v), (float *)(V3_19ae50 *)(&f.b));
            }
            proj->f40 = f.b;
            Cfg_19ae50 *c4 = cfg;
            hulk_freg f5c = c4->f5c;
            proj->f4c = f5c;
            hulk_freg m = f5c * f24;
            double bxm = (double)f.b.x * m;
            f.bm.y = f.b.y * m;
            f.bm.z = f.b.z * m;
            f.P.x = 0.0f;
            f.P.y = 0.0f;
            f.P.z = 0.0f;
            f.a.x = (float)(bxm + f.a.x);
            f.a.y = f.bm.y + f.a.y;
            f.a.z = f.bm.z + f.a.z;
            f.ctx->FUN_00059a50(&f.P);
            f.P.y = f.a.y;
            proj->f28 = f.P;
            proj->f34 = f.a;
            f.pool->FUN_001b6d00(slot, proj);
            proj->Release();
        }
    } while (f24 > f.period);
    return true;
}


// 0x0019b350 hulkfight::motion::ProjectileEffect::vfunc_2 (98 B): matches/0x0019b350.cpp
// sym: ?vfunc_2@ProjectileEffect@fn_f740ace1@@UAEPAV12@E@Z
ProjectileEffect* ProjectileEffect::vfunc_2(unsigned char flags) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0041b3f4);
    if (m1c) {
        H* h = FUN_0027f250();
        h->Fn_0027ffb0(m1c);
    }
    if (m24) {
        m24->B();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Cleanup_001b6820();
    if (flags & 1)
        ((Global_19b350*)((hulk_intptr)DAT_004e2210))->Free_0008ff00(this, 0x50);
    return this;
}

} // namespace fn_f740ace1

// 0x0019b3c0 hulkfight::motion::FireMissileTrack::vfunc_10 (70 B): matches/0x0019b3c0.cpp
// sym: ?vfunc_10@FireMissileTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FireMissileTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&TypeA_19b3c0), (void*)(&TypeB_19b3c0), 0));
    if (result) {
        Object_19b3c0* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_00196220(this, c);
    }
    return 0;
}

namespace fn_f740ace1 {

// 0x0019b410 hulkfight::motion::FireMissileAction::vfunc_2 (71 B): matches/0x0019b410.cpp
// sym: ?vfunc_2@FireMissileAction_19b410@fn_f740ace1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
FireMissileAction_19b410* FireMissileAction_19b410::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041b414;
    RefCounted_19b410* q = *(RefCounted_19b410* volatile*)&m_20;
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

} // namespace fn_f740ace1

// 0x0019b460 FUN_0019b460 (157 B): equivalent/0x0019b460.cpp [wrapped: conflict: CProjectile; FUN_0027f250; World; hulkfight::motion::ProjectileMissile]
// sym: ??1ProjectileMissile@motion@hulkfight@fn_0019b460@@UAE@XZ @667ead3e9f14 @wb2f2fe593d89
namespace fn_0019b460 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0019b460 @ 0x0019b460
// hulkfight::motion::ProjectileMissile::~ProjectileMissile body @ 0x0019b460
// equiv-map: ??1CProjectile@@UAE@XZ = 0x001b6820
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

struct Id64_19b460 {
    int lo;
    int hi;
};

struct MissileCfg_19b460 {
    char pad0[0x20];
    Id64_19b460 id;                // 0x20
};

class RefObj_19b460 {
public:
    virtual void v0();
    virtual void Release();
};

struct Factory_19b460 {
    bool FUN_001dd800(int handle);
    int FUN_001e3020(int handle, int lo, int hi);
    int FUN_001dc290(int handle);
    void FUN_001e5bc0(int handle);
};

struct World {
    char pad0[0xc];
    Factory_19b460 *factory;       // 0xc
};

struct Pool_19b460 {
    void FUN_002834e0(int v);
};

Pool_19b460 *FUN_0027f250();

class CProjectile {
public:
    virtual ~CProjectile() throw();
    char pad04[0x3c - 4];
};

namespace hulkfight {
namespace motion {

class ProjectileMissile : public CProjectile {
public:
    virtual ~ProjectileMissile() throw();
    MissileCfg_19b460 *cfg;        // 0x3c
    int handle;             // 0x40
    char pad44[0xc];
    RefObj_19b460 *owner;          // 0x50
    char pad54[0xa0 - 0x54];
    int fa0;
};

ProjectileMissile::~ProjectileMissile() throw()
{
    if (owner)
        owner->Release();
    owner = 0;

    Pool_19b460 *pool = FUN_0027f250();
    pool->FUN_002834e0(fa0);

    Factory_19b460 *factory = DAT_004dd700->factory;
    bool keep = false;
    if (factory->FUN_001dd800(handle)) {
        int lo = cfg->id.lo;
        int hi = cfg->id.hi;
        if ((lo | hi) != 0) {
            int found = factory->FUN_001e3020(handle, lo, hi);
            int current = factory->FUN_001dc290(handle);
            keep = (found >= 0 && current == found);
        }
    }
    if (!keep)
        factory->FUN_001e5bc0(handle);

    cfg = 0;
}

}
}
} // namespace fn_0019b460
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0019b500 FUN_0019b500 (206 B): equivalent/0x0019b500.cpp [wrapped: conflict: hulkfight::motion::BeamEffect; hulkfight::motion::FireBeamAction]
// sym: ??0FireBeamAction@motion@hulkfight@fn_0019b500@@QAE@HPAURef_19b500@3@@Z @5cd1a1e0fb45 @we676446088a4
void* __cdecl operator new(size_t);
namespace fn_0019b500 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0019b500 @ 0x0019b500

struct Ref_19b500 { virtual void AddRef(); virtual void Release(); };
struct FUN_00232660 { virtual void baseSlot(); char pad[24]; FUN_00232660(); };
namespace hulkfight { namespace motion {
struct BeamEffect {
 virtual void slot0();
 int owner; int a8,aC,a10,a14,a18,a1C,a20,a24,a28; float a2C; int a30;
};
struct FireBeamAction : FUN_00232660 {
 int owner; Ref_19b500* ref; int a24,a28,a2C,a30,a34,a38,a3C; char pad40[12]; int a4C,a50; char pad54[12]; int a60,a64; BeamEffect* effect; char pad6C[24]; int a84,a88; float a8C;
 virtual void baseSlot();
 FireBeamAction(int,Ref_19b500*);
};
FireBeamAction::FireBeamAction(int o,Ref_19b500* r) {
 owner=0; ref=0; a30=0; a34=0; a38=0; a3C=0; a4C=0; a50=0; a60=0; a64=0; effect=0; a84=0; a88=0; a8C=-1.0f;
 owner=o;
 if(r) r->AddRef();
 if(ref) ref->Release();
 ref=r; a2C=0; a28=0; a24=0;
 BeamEffect* e=new BeamEffect;
 if(e) { e->owner=o; e->a8=0;e->aC=0;e->a10=0;e->a14=0;e->a18=0;e->a1C=0;e->a20=0;e->a24=0;e->a28=0;e->a2C=-1.0f;e->a30=0; }
 effect=e;
}
}}
} // namespace fn_0019b500


// 0x0019b5d0 hulkfight::motion::FireBeamAction::vfunc_2 (30 B): matches/0x0019b5d0.cpp
// sym: ??_GFireBeamAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::FireBeamAction::~FireBeamAction() {}

namespace fn_f740ace1 {

// 0x0019b5f0 hulkfight::motion::FireBeamAction::vfunc_5 (576 B): equivalent/0x0019b5f0.cpp
// sym: ?vfunc_5@FireBeamAction@fn_f740ace1@@UAE_NHM@Z @8028090db355 @wc52888d208f0
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/18)
// hulkfight::motion::FireBeamAction::vfunc_5 @ 0x0019b5f0
bool FireBeamAction::vfunc_5(int phase, float dt)
{
    if (phase == 1) {
        Fighter_19b5f0* fighter = FUN_00059a30(FUN_000592a0(owner));
        FUN_00197610(dt);
        time = dt + time;
        state->f10 = owner->f8;

        Vec3_19b5f0 origin;
        Vec3_19b5f0 dir;
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = -1.0f;
        if (skeleton != 0) {
            Mat_19b5f0 m;
            Mat_19b5f0* src = &skeleton->mats[jointIndex];
            if (source != 0) {
                Mat_19b5f0* other = source->vfunc_15();
                ((owners::Matrix_22ca90 *)&m)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat_19b5f0 *)src, (const owners::Matrix_22ca90 *)(Mat_19b5f0 *)other);
            } else {
                m = *src;
            }
            Vec3_19b5f0 local = cfg->v38;
            ((owners::Mat_22c2b0 *)&m)->FUN_0022c2b0((float *)(const Vec3_19b5f0 *)(&local), (float *)(Vec3_19b5f0 *)(&origin));
            local = cfg->v44;
            ((owners::M_22c3b0 *)&m)->FUN_0022c3b0((float *)(const Vec3_19b5f0 *)(&local), (float *)(Vec3_19b5f0 *)(&dir));
            dir.FUN_0022d110();
        }

        Beam_19b5f0* b = beam;
        if (b == 0) {
            b = fighter->beam;
            if (b == 0) {
                // the original spills the creation arguments into its argument slot, which the
                // trace helper below later receives as an output cell
                int a58 = cfg->f58;
                phase = a58;
                int a54 = cfg->f54;
                b = fighter->FUN_00039c60(&origin, &dir, a54, a58, 0, 0, 0);
            }
        }
        Beam_19b5f0** slot = &state->ref;
        if (b)
            b->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = b;

        if (b != 0 && cfg->f60) {
            Vec3_19b5f0 hit = b->pos;
            FUN_00096b50(b, &hit, &phase);
            dir.x = hit.x - origin.x;
            dir.y = hit.y - origin.y;
            dir.z = hit.z - origin.z;
            dir.FUN_0022d110();
        }

        state->dir = dir;
        state->origin = origin;
        state->f30 = cfg->f50;
        state->FUN_00197ff0(dt);
    }
    return true;
}


// 0x0019b830 hulkfight::motion::BeamEffect::vfunc_0 (64 B): matches/0x0019b830.cpp
// sym: ?f2@BeamEffect_19b830@fn_f740ace1@@QAEPAV12@E@Z
BeamEffect_19b830* BeamEffect_19b830::f2(unsigned char flags) {
    vptr = hulk_at_0041b4a0;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m4)
        m4 = 0;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f740ace1

// 0x0019b870 hulkfight::motion::AccuracyLatencyTrack::vfunc_10 (70 B): matches/0x0019b870.cpp
// sym: ?vfunc_10@AccuracyLatencyTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AccuracyLatencyTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_19b870 a = (u32_19b870)__p0; u32_19b870 b = (u32_19b870)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_19b870, &hulk_at_00494b60, 0)) {
        Params_19b870* q = (Params_19b870*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_001984c0(this, p);
    }
    return 0;
}

namespace fn_f740ace1 {

// 0x0019b8c0 hulkfight::motion::AccuracyLatencyAction::vfunc_2 (71 B): matches/0x0019b8c0.cpp
// sym: ?vfunc_2@AccuracyLatencyAction_19b8c0@fn_f740ace1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
AccuracyLatencyAction_19b8c0* AccuracyLatencyAction_19b8c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041b4a8;
    RefCounted_19b8c0* q = *(RefCounted_19b8c0* volatile*)&m_20;
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


// 0x0019b960 hulkfight::motion::MissileThrowAction::vfunc_2 (71 B): matches/0x0019b960.cpp
// sym: ?vfunc_2@MissileThrowAction_19b960@fn_f740ace1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MissileThrowAction_19b960* MissileThrowAction_19b960::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041b4c4;
    RefCounted_19b960* q = *(RefCounted_19b960* volatile*)&m_20;
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


// 0x0019ba00 hulkfight::motion::FireGroundShockwaveAction::vfunc_2 (71 B): matches/0x0019ba00.cpp
// sym: ?vfunc_2@FireGroundShockwaveAction_19ba00@fn_f740ace1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
FireGroundShockwaveAction_19ba00* FireGroundShockwaveAction_19ba00::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0041b4e0;
    RefCounted_19ba00* q = *(RefCounted_19ba00* volatile*)&m_20;
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

} // namespace fn_f740ace1

// 0x0019bbd0 hulkfight::motion::ProjectileGroundShockwave::vfunc_2 (37 B): matches/0x0019bbd0.cpp [wrapped: conflict: CProjectile]
// sym: ?vfunc_2@ProjectileGroundShockwave@fn_0019bbd0@@UAEPAV12@E@Z
namespace fn_0019bbd0 {

class CProjectile {
    char pad[0x20];
};
class ProjectileGroundShockwave : public CProjectile {
  public:
    virtual void v0();
    virtual void v1();
    virtual ProjectileGroundShockwave* vfunc_2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
struct ThisCall_00198ab0 {
    void FUN_00198ab0();
};
struct Alloc_19bbd0 {
    void Fnf_0008ff00(void*, int);
};
ProjectileGroundShockwave* ProjectileGroundShockwave::vfunc_2(unsigned char flags) {
    ((ThisCall_00198ab0*)(this))->FUN_00198ab0();
    if (flags & 1)
        ((Alloc_19bbd0*)((hulk_intptr)DAT_004e2210))->Fnf_0008ff00(this, 0xc0);
    return this;
}
} // namespace fn_0019bbd0

namespace fn_f740ace1 {

// 0x0019bc50 hulkfight::motion::MissilePunchAction::vfunc_2 (71 B): matches/0x0019bc50.cpp
// sym: ?vfunc_2@MissilePunchAction_19bc50@fn_f740ace1@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MissilePunchAction_19bc50* MissilePunchAction_19bc50::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_19bc50;
    RefCounted_19bc50* q = *(RefCounted_19bc50* volatile*)&m_20;
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

} // namespace fn_f740ace1

// 0x0019bd20 fight::ParamName<hulkfight::motion::FireProjectileTrack>::vfunc_7 (12 B): matches/0x0019bd20.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019bd20@@UAEXPAX@Z
namespace fn_0019bd20 {
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
} // namespace fn_0019bd20


// 0x0019bd50 fight::ParamNameConstList<hulkfight::motion::FireProjectileTrack>::vfunc_7 (12 B): matches/0x0019bd50.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019bd50@@UAEXPAX@Z
namespace fn_0019bd50 {
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
} // namespace fn_0019bd50


// 0x0019be00 fight::ParamName<hulkfight::motion::FireBeamTrack>::vfunc_7 (12 B): matches/0x0019be00.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019be00@@UAEXPAX@Z
namespace fn_0019be00 {
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
} // namespace fn_0019be00


// 0x0019be30 fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>::vfunc_7 (12 B): matches/0x0019be30.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019be30@@UAEXPAX@Z
namespace fn_0019be30 {
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
} // namespace fn_0019be30


// 0x0019be80 fight::ParamName<hulkfight::motion::FireMissileTrack>::vfunc_7 (12 B): matches/0x0019be80.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019be80@@UAEXPAX@Z
namespace fn_0019be80 {
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
} // namespace fn_0019be80


// 0x0019beb0 fight::ParamNameConstList<hulkfight::motion::FireMissileTrack>::vfunc_7 (12 B): matches/0x0019beb0.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019beb0@@UAEXPAX@Z
namespace fn_0019beb0 {
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
} // namespace fn_0019beb0


// 0x0019bf00 fight::ParamName<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_7 (12 B): matches/0x0019bf00.cpp [wrapped: same definition as 0x00199910 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_0019bf00@@UAEXPAX@Z
namespace fn_0019bf00 {
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
} // namespace fn_0019bf00


// 0x0019bf10 fight::ParamName<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019bf10.cpp
// sym: ??_G?$ParamName@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FireProjectileTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bf10)
#endif


// 0x0019bf30 fight::ParamNameConstList<hulkfight::motion::FireProjectileTrack>::vfunc_0 (30 B): matches/0x0019bf30.cpp
// sym: ??_G?$ParamNameConstList@VFireProjectileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::FireProjectileTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::FireProjectileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bf30)
#endif


// 0x0019bf50 fight::ParamName<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019bf50.cpp
// sym: ??_G?$ParamName@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FireBeamTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bf50)
#endif


// 0x0019bf70 fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>::vfunc_0 (30 B): matches/0x0019bf70.cpp
// sym: ??_G?$ParamNameConstList@VFireBeamTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::FireBeamTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bf70)
#endif


// 0x0019bf90 fight::ParamName<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019bf90.cpp
// sym: ??_G?$ParamName@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FireMissileTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bf90)
#endif


// 0x0019bfb0 fight::ParamNameConstList<hulkfight::motion::FireMissileTrack>::vfunc_0 (30 B): matches/0x0019bfb0.cpp
// sym: ??_G?$ParamNameConstList@VFireMissileTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::motion::FireMissileTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::motion::FireMissileTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bfb0)
#endif


// 0x0019bfd0 fight::ParamName<hulkfight::motion::FireGroundShockwaveTrack>::vfunc_0 (30 B): matches/0x0019bfd0.cpp
// sym: ??_G?$ParamName@VFireGroundShockwaveTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::motion::FireGroundShockwaveTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::motion::FireGroundShockwaveTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x19bfd0)
#endif

