// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00117ce0..0x0011b800 (kind game, layer game, confidence high), dominant class hulkfight::ai::MotionClosestWaypointAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffc509e9 {
#define TREE_TU_END }
namespace fn_ffc509e9 {} using namespace fn_ffc509e9;
#include "game/hulkfight/ai.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_ffc509e9 {
extern "C" char DAT_0040ed74[];
struct RefObj_117ce0 {
    virtual void addRef();
    virtual void release();
};
struct Name_117ce0 {
    char data[8];
    void FUN_0027af00();
};
struct MotionClosestWaypointAction {
    hulk_intptr vptr;
    char pad04[0x18];
    int f1c;
    RefObj_117ce0 *f20;
    char pad24[0xc];
    int f30;
    int f34;
    int f38;
    char pad3c[0xc];
    int f48;
    char pad4c[0xc];
    char f58;
    char pad59[3];
    int f5c;
    Name_117ce0 name;
    void FUN_00232660();
    MotionClosestWaypointAction *FUN_00117ce0(int a, RefObj_117ce0 *target);
};
extern void* hulk_at_0040ed74[];
class Ref_117d60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_117d60 {
  public:
    void* vptr;
};
struct Sub_117d60 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_117d60*) throw();
void __fastcall SubFini2(Sub_117d60*) throw();
void __fastcall SubFini3(Sub_117d60*) throw();
class MotionClosestWaypointAction_117d60 : public Action_117d60 {
  public:
    char p1c[24];
    void* m1c;
    Ref_117d60* m20;
    char p60[60];
    Sub_117d60 s60;
    ~MotionClosestWaypointAction_117d60() throw();
};
class CStageCondition_118280;
class ParamValue_118280 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118280 : public ParamValue_118280 {
  public:
    int pad;
};
struct CAxisArcCondition_1182c0;
class CStageCondition_1182d0 {};
class ParamValue_1182d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1182d0 : public ParamValue_1182d0 {
  public:
    virtual void f();
};
class CStageCondition_118360;
class ParamValue_118360 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118360 : public ParamValue_118360 {
  public:
    int pad;
};
class CStageCondition_1183b0;
class ParamValue_1183b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1183b0 : public ParamValue_1183b0 {
  public:
    int pad;
};
class CStageCondition_118400;
class ParamValue_118400 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118400 : public ParamValue_118400 {
  public:
    int pad;
};
class CStageCondition_118450;
class ParamValue_118450 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118450 : public ParamValue_118450 {
  public:
    int pad;
};
class CStageCondition_1184a0;
class ParamValue_1184a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1184a0 : public ParamValue_1184a0 {
  public:
    int pad;
};
class CStageCondition_1184f0;
class ParamValue_1184f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1184f0 : public ParamValue_1184f0 {
  public:
    int pad;
};
class CStageCondition_118540;
class ParamValue_118540 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118540 : public ParamValue_118540 {
  public:
    int pad;
};
class CStageCondition_118590;
class ParamValue_118590 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118590 : public ParamValue_118590 {
  public:
    int pad;
};
class CStageCondition_1185e0;
class ParamValue_1185e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1185e0 : public ParamValue_1185e0 {
  public:
    int pad;
};
class CStageCondition_118630;
class ParamValue_118630 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118630 : public ParamValue_118630 {
  public:
    int pad;
};
class CStageCondition_118680;
class ParamValue_118680 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118680 : public ParamValue_118680 {
  public:
    int pad;
};
class CStageCondition_1186d0;
class ParamValue_1186d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1186d0 : public ParamValue_1186d0 {
  public:
    int pad;
};
class CStageCondition_118720;
class ParamValue_118720 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118720 : public ParamValue_118720 {
  public:
    int pad;
};
class CStageCondition_118770;
class ParamValue_118770 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118770 : public ParamValue_118770 {
  public:
    int pad;
};
class CStageCondition_1187c0;
class ParamValue_1187c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1187c0 : public ParamValue_1187c0 {
  public:
    int pad;
};
class CStageCondition_118810;
class ParamValue_118810 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118810 : public ParamValue_118810 {
  public:
    int pad;
};
class CStageCondition_118860;
class ParamValue_118860 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_118860 : public ParamValue_118860 {
  public:
    int pad;
};
class CStageCondition_1188b0;
class ParamValue_1188b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1188b0 : public ParamValue_1188b0 {
  public:
    int pad;
};
extern void* hulk_at_00491ca8;
extern void* hulk_at_004a54b8;
class HasGroundPointCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class CF {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};
extern char DAT_00491ca8;
extern char DAT_004a5570;
extern "C" int FUN_00344e74(hulk_intptr, int, void*, void*, int);
class ConditionFactoryCaster_118930 {
  public:
    virtual void f0();
    virtual void f1();
};
extern char DAT_004a5628;
} // namespace fn_ffc509e9
namespace fight {
class ConditionFactoryCaster_1189b0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class ComputeDropZoneCondition_1189b0 {};
} }
namespace fn_ffc509e9 {
extern int g1;
} // namespace fn_ffc509e9
namespace fight {
class ConditionFactoryCaster_118a30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class HasGroundPointExtendedCondition_118a30;
} }
namespace fight {
class TrackFactoryCaster_118ad0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionFleeTrack_118ad0;
} }
namespace fn_ffc509e9 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004a57a0;
extern char DAT_004a5848;
} // namespace fn_ffc509e9
namespace fight {
class TrackFactoryCaster_118b30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionStopTrack_118b30;
} }
namespace fight {
class TrackFactoryCaster_118b90 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionFacingTrack_118b90 {};
} }
namespace fn_ffc509e9 {
extern char DAT_004a58f0;
} // namespace fn_ffc509e9
namespace fight {
class TrackFactoryCaster_118c10 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionBoostTrack_118c10 {};
} }
namespace fn_ffc509e9 {
extern char DAT_004a5998;
extern char DAT_004a5a40;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);
class TrackFactoryCaster_118c70 {
  public:
    virtual int vfunc_0(int a);
};
extern char DAT_004a5ae8;
} // namespace fn_ffc509e9
namespace fight {
class TrackFactoryCaster_118cf0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionTargetTrack_118cf0 {};
} }
namespace fn_ffc509e9 {
extern "C" int FindTrack(void*, int, void*, void*, int);
extern char DAT_004a5b90;
} // namespace fn_ffc509e9
namespace fight {
class TrackFactoryCaster_118d70 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class MotionChaseTrack_118d70;
} }
namespace fn_ffc509e9 {
extern int hulk_at_0049850c;
class Params_119d10 {
  public:
    int x;
};
extern Params_119d10 hulk_at_00494b44;
extern Params_119d10 hulk_at_00494b60;
class Object_119d10 {
  public:
    int Init_00116910(hulkfight::ai::MotionStopTrack*, hulk_intptr);
};
Object_119d10* __cdecl Alloc_0008d690(int);
struct RefCounted_119d60 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040eca0[];
class MotionStopAction_119d60 {
  public:
    MotionStopAction_119d60* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_119d60* m_20;
};
struct RefCounted_119e00 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040ecbc[];
class MotionFacingAction_119e00 {
  public:
    MotionFacingAction_119e00* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_119e00* m_20;
};
extern int hulk_at_0040ecd8;
class RefObj_119ea0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class MotionTargetAction {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_119ea0* m2;
    RefObj_119ea0* m3;
    void* vfunc_2(unsigned char flag);
};
extern int hulk_at_0040ecf4;
class RefObj_119f50 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class MotionChaseAction_119f50 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_119f50* m2;
    RefObj_119f50* m3;
    void* vfunc_2(unsigned char flag);
};
typedef unsigned int u32_119fb0;
extern int TypeA_119fb0, TypeB;
struct Params_119fb0 {
    int Init_001170b0(hulkfight::ai::MotionBoostTrack*, void*);
};
extern void* Alloc(hulk_uintptr);
extern int hulk_at_0040ed10;
class RefObj_11a000 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class MotionBoostAction_11a000 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_11a000* m2;
    RefObj_11a000* m3;
    void* vfunc_2(unsigned char flag);
};
struct RefCounted_11a0b0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char hulk_at_0040ed2c[];
class MotionLocatorAction_11a0b0 {
  public:
    MotionLocatorAction_11a0b0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_11a0b0* m_20;
};
extern int hulk_at_0040ed48;
class RefObj_11a150 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class MotionFleeAction_11a150 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_11a150* m2;
    RefObj_11a150* m3;
    void* vfunc_2(unsigned char flag);
};
struct TypeInfo_11a1b0 {
    int x;
};
extern TypeInfo_11a1b0 CFightParamsType_11a1b0;
extern TypeInfo_11a1b0 FightParamsType_11a1b0;
void* __cdecl Allocate_0008d690(int);
class Allocated_11a1b0 {
  public:
    int Init_00117ce0(hulkfight::ai::MotionClosestWaypointTrack*, void*);
};
class ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
class ConditionFactoryCasterTemplate_11a980 : public ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
extern void* Find_002343e0(int, ConditionFactoryCaster_11a980*);
class Owner {
  public:
    void Set_00236760(void*);
    void Use_00236760(void*);
};
class ConditionFactoryCaster_11a9b0 {
  public:
    virtual void cast();
};
class ConditionFactoryCasterTemplate_11a9b0 : public ConditionFactoryCaster_11a9b0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set_00236760(void*);
    void use_00236760(void*);
};
void* find_002343e0(const char*, ConditionFactoryCaster_11a9b0*);
class ConditionFactoryCasterTemplate_11a9e0 {
  public:
    virtual bool cast_001189b0(void*);
};
extern "C" void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_11a9e0*);
class ConditionFactoryCasterTemplate_11aa10 {
  public:
    virtual bool Cast_00118a30(void*);
};
void* Find_002343e0(void*, ConditionFactoryCasterTemplate_11aa10*);
} // namespace fn_ffc509e9
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_ffc509e9 {
class TrackFactoryTemplate_11af80 {
  public:
    TrackFactoryTemplate_11af80() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct Init_11afc0 {
    void init_00234590(int);
};
extern char hulk_at_0040eaa0;
struct HasGroundPointCondition_11afc0 {
    char pad[12];
    unsigned char x;
    unsigned char y;
};
void* __cdecl alloc_0008d690(hulk_uintptr);
extern int hulk_at_0040f2d8;
struct ConditionFactoryTemplate_11aff0 {
    void* m_vptr;
    void base1_dtor_001156a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_11b020 {
  public:
    TrackFactoryTemplate_11b020() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040eac0[];
class LocatorDistanceCondition_11b060 {
  public:
    LocatorDistanceCondition_11b060(int);
};
extern int hulk_at_0040f2f4;
struct ConditionFactoryTemplate_11b0a0 {
    void* m_vptr;
    void base1_dtor_00115700();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_11b0d0 {
  public:
    TrackFactoryTemplate_11b0d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040eae0[];
class Obj_11b110 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_0040f310;
struct ConditionFactoryTemplate_11b160 {
    void* m_vptr;
    void base1_dtor_00115770();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_11b190 {
  public:
    TrackFactoryTemplate_11b190() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
} // namespace fn_ffc509e9
void* operator new(size_t);
namespace fn_ffc509e9 {
class BaseCondition {
  public:
    virtual void v0();
    char pad[8];
    unsigned char a, b, c, d, e, f;
    BaseCondition(int) throw();
};
class IntermediateCondition : public BaseCondition {
  public:
    IntermediateCondition() throw() : BaseCondition(0) {
        a = 1;
        b = 1;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
    }
};
class HasGroundPointExtendedCondition_11b1d0 : public IntermediateCondition {
  public:
    float x, y;
    int p, q, r;
    HasGroundPointExtendedCondition_11b1d0() throw() : IntermediateCondition() {
        _ReadWriteBarrier();
        x = 1.0f;
        y = 2.0f;
        _ReadWriteBarrier();
        p = 0;
        q = 0;
        r = 0;
    }
    virtual void v0();
};
extern int hulk_at_0040f32c;
struct ConditionFactoryTemplate_11b230 {
    void* m_vptr;
    void base1_dtor_001157f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_11b260 {
  public:
    TrackFactoryTemplate_11b260() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct MotionFleeTrack_11b2a0 {
    hulk_intptr vtable;
    char pad4[8];
    int a;
    int b;
    int c;
    void ctor_00236d40();
};
extern char hulk_at_0040eb20;
extern int hulk_at_0040f348;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115880();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_11b310 {
  public:
    TrackFactoryTemplate_11b310() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040eb50[];
typedef unsigned int u32_11b350;
class MotionStopTrack_11b350 {
  public:
    MotionStopTrack_11b350();
    hulk_uintptr a;
    u32_11b350 b;
    u32_11b350 c;
    int x;
    float y;
};
class TrackFactoryTemplate_11b3c0 {
  public:
    TrackFactoryTemplate_11b3c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
} // namespace fn_ffc509e9
namespace hulkfight { namespace ai {
class BaseTrack {
  public:
    virtual void f();
    char pad[8];
    BaseTrack() throw();
};
} }
namespace hulkfight { namespace ai {
struct FacingData {
    int a;
    float b;
    int c;
    FacingData() throw() {
        a = 0;
        _ReadWriteBarrier();
        b = -1.0f;
        c = 0;
        _ReadWriteBarrier();
    }
};
} }
namespace hulkfight { namespace ai {
class MotionFacingTrack_11b400 : public BaseTrack, public FacingData {
  public:
    virtual void f();
    int d;
    int e;
    float g;
    float h;
    MotionFacingTrack_11b400() throw() {
        _ReadWriteBarrier();
        d = 0;
        e = 0;
        g = -1.0f;
        h = 1.0f;
    }
};
} }
namespace fight {
class TrackFactory_11b400 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::ai::MotionFacingTrack_11b400* vfunc_5();
};
}
namespace fn_ffc509e9 {
class TrackFactoryTemplate_11b480 {
  public:
    TrackFactoryTemplate_11b480() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040ebb0[];
typedef unsigned int u32_11b4c0;
struct TrackFactoryTemplate_nv_11b4c0 {
    void initialize_00236d40();
};
class TrackFactoryTemplate_11b540 {
  public:
    TrackFactoryTemplate_11b540() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct B_11b580 {
    B_11b580() throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B_11b580* f5();
    int m4, m8;
};
struct S1_11b580 {
    int a;
    float b;
    int c;
    S1_11b580() throw() {
        a = 0;
        _ReadWriteBarrier();
        b = -1.0f;
        _ReadWriteBarrier();
        c = 0;
    }
};
struct S2_11b580 {
    int d;
    int e;
    float f;
    float g;
    S2_11b580() throw() {
        d = 0;
        e = 0;
        f = -1.0f;
        g = 1.0f;
    }
};
struct T_11b580 : B_11b580, S1_11b580 {
    S2_11b580 s2;
    T_11b580() throw() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B_11b580* f5();
};
class TrackFactoryTemplate_11b600 {
  public:
    TrackFactoryTemplate_11b600() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_11b6c0 {
  public:
    TrackFactoryTemplate_11b6c0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class TrackFactoryTemplate_11b750 {
  public:
    TrackFactoryTemplate_11b750() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Track_11b790 {
  public:
    hulk_intptr method_00115b00();
};


// 0x00117ce0 FUN_00117ce0 (116 B): matches/0x00117ce0.cpp
// sym: ?FUN_00117ce0@MotionClosestWaypointAction@fn_ffc509e9@@QAEPAU12@HPAURefObj_117ce0@2@@Z
// FUN_00117ce0 @ 0x00117ce0
MotionClosestWaypointAction *MotionClosestWaypointAction::FUN_00117ce0(int a, RefObj_117ce0 *target)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_0040ed74;
    f1c = 0;
    f20 = 0;
    f30 = 0;
    f34 = 0x7f7fffff;
    f38 = 0x7f7fffff;
    f48 = 0;
    f58 = 0;
    f5c = 0;
    name.FUN_0027af00();
    f1c = a;
    if (target)
        target->addRef();
    if (f20)
        f20->release();
    f20 = target;
    ((owners::Target_27b040 *)&name)->FUN_0027b040((hulk_uintptr)"waypoint_stuck");
    return this;
}


// 0x00117d60 FUN_00117d60 (58 B): matches/0x00117d60.cpp
// sym: ??1MotionClosestWaypointAction_117d60@fn_ffc509e9@@QAE@XZ
MotionClosestWaypointAction_117d60::~MotionClosestWaypointAction_117d60() throw() {
    vptr = hulk_at_0040ed74;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    FUN_0027af50(&s60);
    ((fight::Action *)(Action_117d60 *)this)->FUN_002326a0();
}

} // namespace fn_ffc509e9

// 0x00117ed0 hulkfight::ai::LocatorDistanceCondition::vfunc_6 (352 B): equivalent/0x00117ed0.cpp [wrapped: conflict: CFightParams; fight::Params]
// sym: ?FUN_00117ed0@LocatorDistanceCondition@fn_00117ed0@@QAE_NHPAVParams@fight@2@H@Z @005afce905b3 @wb3e6233f9004
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00117ed0 {
// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 18/20, incomplete)
// hulkfight::ai::LocatorDistanceCondition::vfunc_6 @ 0x00117ed0
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


struct Vec3_117ed0 {
    float x, y, z;
};

struct Frame_117ed0 {
    Vec3_117ed0 origin;
    Vec3_117ed0 target;
};

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v3();
    virtual void v4();
};

class Locator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(Vec3_117ed0 *out);
};

struct Finder_117ed0 {
    Locator *FUN_001fc8c0(int lo, int hi);
};

struct Anchor_117ed0 {
    void FUN_00059a50(Vec3_117ed0 *out);
};

struct Registry_117ed0 {
    char pad0[0x10];
    Anchor_117ed0 *anchor;
    char pad14[0x1d70 - 0x14];
    int handleLo;
    int handleHi;
};

struct Owner_117ed0 { char pad[4]; };

struct World {
    char pad0[0x28];
    Finder_117ed0 *finder;
};


Owner_117ed0 *__fastcall FUN_000592a0(void *x);
Registry_117ed0 *__fastcall FUN_00059a30(Owner_117ed0 *o);
extern "C" bool __cdecl FUN_00018960(float a, float b, float eps);

struct LocatorDistanceCondition {
    char pad0[0xc];
    int mode;
    float threshold;
    bool FUN_00117ed0(int a1, fight::Params *params, int a3);
};

bool LocatorDistanceCondition::FUN_00117ed0(int a1, fight::Params *params, int a3)
{
    Frame_117ed0 f;

    if (!dynamic_cast<CFightParams *>(params))
        return false;

    Registry_117ed0 *reg = FUN_00059a30(FUN_000592a0(params));
    f.origin.x = 0.0f;
    f.origin.y = 0.0f;
    f.origin.z = 0.0f;
    reg->anchor->FUN_00059a50(&f.origin);

    int lo = reg->handleLo;
    int hi = reg->handleHi;
    if ((lo | hi) == 0)
        return false;

    Locator *loc = DAT_004dd700->finder->FUN_001fc8c0(lo, hi);
    if (!loc)
        return false;

    loc->v8(&f.target);
    float dx = f.target.x - f.origin.x;
    unsigned int m = (unsigned int)mode;
    float dz = f.target.z - f.origin.z;
    float dist = (float)sqrt(dz * dz + dx * dx);
    if (m > 5)
        return false;

    switch (m) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 0.00001f);
    case 3:
        return !FUN_00018960(dist, threshold, 0.00001f);
    case 4:
        return dist >= threshold;
    default:
        return dist > threshold;
    }
}
} // namespace fn_00117ed0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00118050 hulkfight::ai::HasGroundPointExtendedCondition::vfunc_6 (486 B): equivalent/0x00118050.cpp [wrapped: conflict: World]
// sym: ?vfunc_6@HasGroundPointExtendedCondition@fn_00118050@@UAEDHPAXH@Z @e1ccb3ea3f6e @wabd09e94bdde
namespace fn_00118050 {
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 18/18)
// hulkfight::ai::HasGroundPointExtendedCondition::vfunc_6 @ 0x00118050
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

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3_118050 {
    float x, y, z;
};

struct Body_118050 {
    char pad00[0x40];
    V3_118050 pos;
};

struct Locator {
    char FUN_00059a50(V3_118050 *out);
};

struct Res_118050 {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body_118050 *body;
    char pad32c[0x2064 - 0x32c];
    V3_118050 vel;
};

struct Resolver_118050 {
    Res_118050 *FUN_00059a30();
};

struct Target_118050 {
};

struct Hit_118050 {
    char pad00[0x16];
    unsigned short info;
};

struct Slot_118050 {
};

struct Mgr_118050 {
    void FUN_001dcf60(int a);
};

struct World {
    char pad00[0xc];
    Mgr_118050 *mgr;
    char pad10[0x20 - 0x10];
    Slot_118050 *slot;
};


extern "C" char __cdecl FUN_00202560(V3_118050 *from, float dist, int flag, V3_118050 *outA, V3_118050 *outB, int p6, int p7, Hit_118050 **outHit);
extern "C" V3_118050 *__cdecl FUN_00083e00(V3_118050 *out, V3_118050 *in, float s);

struct Frame_118050 {
    V3_118050 pos;
    V3_118050 w;
    V3_118050 tmp;
    V3_118050 outA;
    V3_118050 ret;
    V3_118050 outB;
};

class HasGroundPointExtendedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, void *obj, int c);
    char pad04[9];
    char useVel;
    char pad0e;
    char useBody;
    char useScaled;
    char useAbs;
    char pad12[2];
    float scale;
    float limit;
    V3_118050 dir;
};

char HasGroundPointExtendedCondition::vfunc_6(int a, void *obj, int c)
{
    Frame_118050 f;
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res_118050 *r = ((Resolver_118050 *)((owners::Object_592a0 *)(((Target_118050 *)obj)))->FUN_000592a0())->FUN_00059a30();
    if (!r)
        return 0;
    if (!useBody) {
        r->loc->FUN_00059a50(&f.pos);
    } else {
        Body_118050 *body = r->body;
        if (!body)
            return 0;
        f.pos = body->pos;
    }
    Hit_118050 *hit = 0;
    if (useVel) {
        hulk_freg s = scale;
        f.tmp.x = s * r->vel.x;
        f.tmp.y = s * r->vel.y;
        f.tmp.z = s * r->vel.z + f.pos.z;
        f.w.z = f.tmp.z;
        f.w.x = f.tmp.x + f.pos.x;
        f.w.y = f.tmp.y + f.pos.y;
    } else if (useScaled) {
        f.tmp = dir;
        V3_118050 *p = FUN_00083e00(&f.ret, &f.tmp, scale);
        f.tmp.z = f.pos.z + p->z;
        f.w.z = f.tmp.z;
        f.w.x = f.pos.x + p->x;
        f.w.y = f.pos.y + p->y;
    }
    ((owners::C_25260 *)(DAT_004dd700->slot))->FUN_00025260(0, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(0);
    char found = FUN_00202560(&f.w, 20.0f, 1, &f.outA, &f.outB, 0, 0, &hit);
    ((owners::C_25260 *)(DAT_004dd700->slot))->FUN_00025260(1, 0, 0);
    DAT_004dd700->mgr->FUN_001dcf60(1);
    if (found) {
        hulk_freg v = f.outA.y - f.w.y;
        if (useAbs) {
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = v;
            bits.u &= 0x7fffffff;
            v = bits.f;
        }
        if (!(v < limit))
            return 0;
    }
    return 1;
}
} // namespace fn_00118050
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00118260 fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::vfunc_6 (26 B): matches/0x00118260.cpp
// sym: ?vfunc_6@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::HasGroundPointCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::**)(int))&this->f_10))(b);
}


// 0x00118280 fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::vfunc_2 (11 B): matches/0x00118280.cpp
// sym: ?vfunc_2@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001182c0 fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_7 (6 B): matches/0x001182c0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001182d0 fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_6 (30 B): matches/0x001182d0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1182d0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1182d0*)&DAT_003f335c));
}


// 0x001182f0 fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_8 (26 B): matches/0x001182f0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x00118310 fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_2 (11 B): matches/0x00118310.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00118340 fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::vfunc_6 (26 B): matches/0x00118340.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x00118360 fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::vfunc_2 (11 B): matches/0x00118360.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118390 fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::vfunc_6 (26 B): matches/0x00118390.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::**)(int))&this->f_10))(b);
}


// 0x001183b0 fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::vfunc_2 (11 B): matches/0x001183b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001183e0 fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::vfunc_6 (26 B): matches/0x001183e0.cpp
// sym: ?vfunc_6@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::**)(int))&this->f_10))(b);
}


// 0x00118400 fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::vfunc_2 (11 B): matches/0x00118400.cpp
// sym: ?vfunc_2@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118430 fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6 (26 B): matches/0x00118430.cpp
// sym: ?vfunc_6@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))(b);
}


// 0x00118450 fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2 (11 B): matches/0x00118450.cpp
// sym: ?vfunc_2@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118480 fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6 (26 B): matches/0x00118480.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))(b);
}


// 0x001184a0 fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2 (11 B): matches/0x001184a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001184d0 fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6 (26 B): matches/0x001184d0.cpp
// sym: ?vfunc_6@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::**)(int))&this->f_10))(b);
}


// 0x001184f0 fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2 (11 B): matches/0x001184f0.cpp
// sym: ?vfunc_2@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118520 fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::vfunc_6 (26 B): matches/0x00118520.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::**)(int))&this->f_10))(b);
}


// 0x00118540 fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::vfunc_2 (11 B): matches/0x00118540.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118570 fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::vfunc_6 (26 B): matches/0x00118570.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::**)(int))&this->f_10))(b);
}


// 0x00118590 fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::vfunc_2 (11 B): matches/0x00118590.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001185c0 fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::vfunc_6 (26 B): matches/0x001185c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::**)(int))&this->f_10))(b);
}


// 0x001185e0 fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::vfunc_2 (11 B): matches/0x001185e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118610 fight::ParamVector<hulkfight::ai::MotionFacingTrack>::vfunc_6 (26 B): matches/0x00118610.cpp
// sym: ?vfunc_6@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::MotionFacingTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::MotionFacingTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::MotionFacingTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::MotionFacingTrack>::**)(int))&this->f_10))(b);
}


// 0x00118630 fight::ParamVector<hulkfight::ai::MotionFacingTrack>::vfunc_2 (11 B): matches/0x00118630.cpp
// sym: ?vfunc_2@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::MotionFacingTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118660 fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::vfunc_6 (26 B): matches/0x00118660.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::**)(int))&this->f_10))(b);
}


// 0x00118680 fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::vfunc_2 (11 B): matches/0x00118680.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001186b0 fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::vfunc_6 (26 B): matches/0x001186b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x001186d0 fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::vfunc_2 (11 B): matches/0x001186d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118700 fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::vfunc_6 (26 B): matches/0x00118700.cpp
// sym: ?vfunc_6@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::MotionLocatorTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::**)(int))&this->f_10))(b);
}


// 0x00118720 fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::vfunc_2 (11 B): matches/0x00118720.cpp
// sym: ?vfunc_2@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118750 fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::vfunc_6 (26 B): matches/0x00118750.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x00118770 fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::vfunc_2 (11 B): matches/0x00118770.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001187a0 fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_6 (26 B): matches/0x001187a0.cpp
// sym: ?vfunc_6@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::MotionTargetTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::MotionTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x001187c0 fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_2 (11 B): matches/0x001187c0.cpp
// sym: ?vfunc_2@?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001187f0 fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::vfunc_6 (26 B): matches/0x001187f0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::**)(int))&this->f_10))(b);
}


// 0x00118810 fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::vfunc_2 (11 B): matches/0x00118810.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118840 fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_6 (26 B): matches/0x00118840.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::**)(int))&this->f_10))(b);
}


// 0x00118860 fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_2 (11 B): matches/0x00118860.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00118890 fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_6 (26 B): matches/0x00118890.cpp
// sym: ?vfunc_6@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::**)(int))&this->f_10))(b);
}


// 0x001188b0 fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_2 (11 B): matches/0x001188b0.cpp
// sym: ?vfunc_2@?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_ffc509e9 {

// 0x001188d0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_0 (36 B): matches/0x001188d0.cpp
// sym: ?vfunc_0@CF@fn_ffc509e9@@UAEHH@Z
int CF::vfunc_0(int a) {
    int r = ((int)(hulk_uintptr)__RTDynamicCast((void*)a, 0, &hulk_at_00491ca8, &hulk_at_004a54b8, 0));
    if (r)
        return 1;
    return 0;
}

} // namespace fn_ffc509e9

// 0x00118900 fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::vfunc_0 (30 B): matches/0x00118900.cpp
// sym: ??_G?$ParamBool@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::HasGroundPointCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::HasGroundPointCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118900)
#endif


// 0x00118930 fight::ConditionFactoryCasterTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_0 (36 B): matches/0x00118930.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_0(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return FUN_00344e74(a, 0, (void*)&DAT_00491ca8, (void*)&DAT_004a5570, 0) != 0;
}


// 0x00118960 fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::vfunc_0 (30 B): matches/0x00118960.cpp
// sym: ??_G?$ParamEnumConstList@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::LocatorDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118960)
#endif


// 0x00118980 fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::vfunc_0 (30 B): matches/0x00118980.cpp
// sym: ??_G?$ParamFloatConstRange@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::LocatorDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118980)
#endif


// 0x001189b0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_0 (36 B): matches/0x001189b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VComputeDropZoneCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &DAT_00491ca8, &DAT_004a5628, 0)) != 0;
}


// 0x001189e0 fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::vfunc_0 (30 B): matches/0x001189e0.cpp
// sym: ??_G?$ParamFloatConstRange@VComputeDropZoneCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::ComputeDropZoneCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1189e0)
#endif


// 0x00118a00 fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::vfunc_0 (30 B): matches/0x00118a00.cpp
// sym: ??_G?$ParamBool@VComputeDropZoneCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::ComputeDropZoneCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118a00)
#endif


// 0x00118a30 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0 (36 B): matches/0x00118a30.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&g1), (void*)(&g2), 0)) != 0;
}


// 0x00118a60 fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0 (30 B): matches/0x00118a60.cpp
// sym: ??_G?$ParamBool@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::HasGroundPointExtendedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118a60)
#endif


// 0x00118a80 fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0 (30 B): matches/0x00118a80.cpp
// sym: ??_G?$ParamFloatConstRange@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::HasGroundPointExtendedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118a80)
#endif


// 0x00118aa0 fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0 (30 B): matches/0x00118aa0.cpp
// sym: ??_G?$ParamVector@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::HasGroundPointExtendedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118aa0)
#endif


// 0x00118ad0 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_0 (36 B): matches/0x00118ad0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionFleeTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a57a0, 0) != 0;
}


// 0x00118b00 fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::vfunc_0 (30 B): matches/0x00118b00.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionFleeTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118b00)
#endif


// 0x00118b30 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_0 (36 B): matches/0x00118b30.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionStopTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a5848, 0) != 0;
}


// 0x00118b60 fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::vfunc_0 (30 B): matches/0x00118b60.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionStopTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionStopTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118b60)
#endif


// 0x00118b90 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_0 (36 B): matches/0x00118b90.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionFacingTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a58f0, 0) != 0;
}


// 0x00118bc0 fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::vfunc_0 (30 B): matches/0x00118bc0.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionFacingTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionFacingTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118bc0)
#endif


// 0x00118be0 fight::ParamVector<hulkfight::ai::MotionFacingTrack>::vfunc_0 (30 B): matches/0x00118be0.cpp
// sym: ??_G?$ParamVector@VMotionFacingTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::MotionFacingTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::MotionFacingTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118be0)
#endif


// 0x00118c10 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_0 (36 B): matches/0x00118c10.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionBoostTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a5998, 0) != 0;
}


// 0x00118c40 fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::vfunc_0 (30 B): matches/0x00118c40.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionBoostTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionBoostTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118c40)
#endif


// 0x00118c70 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_0 (36 B): matches/0x00118c70.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return FUN_00344e74(a, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004a5a40, 0) != 0;
}


// 0x00118ca0 fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::vfunc_0 (30 B): matches/0x00118ca0.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionLocatorTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118ca0)
#endif


// 0x00118cc0 fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::vfunc_0 (30 B): matches/0x00118cc0.cpp
// sym: ??_G?$ParamBool@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::MotionLocatorTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::MotionLocatorTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118cc0)
#endif


// 0x00118cf0 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_0 (36 B): matches/0x00118cf0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionTargetTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004a5ae8), 0)) != 0;
}


// 0x00118d20 fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::vfunc_0 (30 B): matches/0x00118d20.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionTargetTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118d20)
#endif


// 0x00118d40 fight::ParamVector<hulkfight::ai::MotionTargetTrack>::vfunc_0 (30 B): matches/0x00118d40.cpp
// sym: ??_G?$ParamVector@VMotionTargetTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::MotionTargetTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::MotionTargetTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118d40)
#endif


// 0x00118d70 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_0 (36 B): matches/0x00118d70.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionChaseTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FindTrack(p, 0, &DAT_0049850c, &DAT_004a5b90, 0) != 0;
}


// 0x00118da0 fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::vfunc_0 (30 B): matches/0x00118da0.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionChaseTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionChaseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118da0)
#endif


// 0x00118dc0 FUN_00118dc0 (9 B): matches/0x00118dc0.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate; hulkfight::ai::MotionClosestWaypointTrack]
// sym: ??0?$TrackFactoryCasterTemplate@VMotionClosestWaypointTrack@ai@hulkfight@fn_00118dc0@@@fight@fn_00118dc0@@QAE@XZ
namespace fn_00118dc0 {
namespace hulkfight {
namespace ai {
class MotionClosestWaypointTrack {};
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    TrackFactoryCasterTemplate();
    virtual void dummy();
};
} // namespace fight
template <> fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::TrackFactoryCasterTemplate() {}
} // namespace fn_00118dc0


// 0x00118dd0 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_0 (36 B): matches/0x00118dd0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMotionClosestWaypointTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00118e00 fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_0 (30 B): matches/0x00118e00.cpp
// sym: ??_G?$ParamFloatConstRange@VMotionClosestWaypointTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::MotionClosestWaypointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118e00)
#endif


// 0x00118e20 fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_0 (30 B): matches/0x00118e20.cpp
// sym: ??_G?$ParamBool@VMotionClosestWaypointTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::MotionClosestWaypointTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x118e20)
#endif


// 0x00119300 FUN_00119300 (213 B): equivalent/0x00119300.cpp [wrapped: conflict: fight::ParamFloatConstRange]
// sym: ?target@fn_00119300@@YAXXZ @1389c2824c64 @w7d99fd560328
namespace fn_00119300 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00119300 @ 0x00119300

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_001150d0();
void __cdecl SetTimeEnd_001150e0();
void __cdecl SetSpeed_00115100();

namespace hulkfight { namespace ai { class MotionFleeTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack> Param;
void __cdecl FUN_002347b0(unsigned int*, Param**, int);
void __cdecl target() {
 if (DAT_004e0c48 == 0) {
  Param* entries[3];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) { p->FUN_00234960("timeBegin"); p = new(p) Param; p->callback = SetTimeBegin_001150d0; }
  entries[0]=p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) { p->FUN_00234960("timeEnd"); p = new(p) Param; p->callback = SetTimeEnd_001150e0; }
  entries[1]=p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) { p->FUN_00234960("speed"); p = new(p) Param; p->callback = SetSpeed_00115100; }
  entries[2]=p;
  FUN_002347b0(&DAT_004e0c44,entries,3);
 }
 ++DAT_004e0c48;
}
} // namespace fn_00119300


// 0x00119d10 hulkfight::ai::MotionStopTrack::vfunc_10 (70 B): matches/0x00119d10.cpp
// sym: ?vfunc_10@MotionStopTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::ai::MotionStopTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = ((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)(&hulk_at_00494b44), (void*)(&hulk_at_00494b60), 0));
    if (result) {
        Object_119d10* p = Alloc_0008d690(0x24);
        if (p)
            return p->Init_00116910(this, c);
    }
    return 0;
}

namespace fn_ffc509e9 {

// 0x00119d60 hulkfight::ai::MotionStopAction::vfunc_2 (71 B): matches/0x00119d60.cpp
// sym: ?vfunc_2@MotionStopAction_119d60@fn_ffc509e9@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MotionStopAction_119d60* MotionStopAction_119d60::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040eca0;
    RefCounted_119d60* q = *(RefCounted_119d60* volatile*)&m_20;
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


// 0x00119e00 hulkfight::ai::MotionFacingAction::vfunc_2 (71 B): matches/0x00119e00.cpp
// sym: ?vfunc_2@MotionFacingAction_119e00@fn_ffc509e9@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MotionFacingAction_119e00* MotionFacingAction_119e00::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040ecbc;
    RefCounted_119e00* q = *(RefCounted_119e00* volatile*)&m_20;
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


// 0x00119ea0 hulkfight::ai::MotionTargetAction::vfunc_2 (90 B): matches/0x00119ea0.cpp
// sym: ?vfunc_2@MotionTargetAction@fn_ffc509e9@@QAEPAXE@Z
void* MotionTargetAction::vfunc_2(unsigned char flag) {
    volatile MotionTargetAction* self = this;
    self->mVptr = &hulk_at_0040ecd8;
    RefObj_119ea0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_119ea0* t2 = self->m2;
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


// 0x00119f50 hulkfight::ai::MotionChaseAction::vfunc_2 (90 B): matches/0x00119f50.cpp
// sym: ?vfunc_2@MotionChaseAction_119f50@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* MotionChaseAction_119f50::vfunc_2(unsigned char flag) {
    volatile MotionChaseAction_119f50* self = this;
    self->mVptr = &hulk_at_0040ecf4;
    RefObj_119f50* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_119f50* t2 = self->m2;
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

} // namespace fn_ffc509e9

// 0x00119fb0 hulkfight::ai::MotionBoostTrack::vfunc_10 (70 B): matches/0x00119fb0.cpp
// sym: ?vfunc_10@MotionBoostTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::MotionBoostTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_119fb0 a = (u32_119fb0)__p0; u32_119fb0 b = (u32_119fb0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_119fb0, &TypeB, 0)) {
        Params_119fb0* q = (Params_119fb0*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_001170b0(this, p);
    }
    return 0;
}

namespace fn_ffc509e9 {

// 0x0011a000 hulkfight::ai::MotionBoostAction::vfunc_2 (90 B): matches/0x0011a000.cpp
// sym: ?vfunc_2@MotionBoostAction_11a000@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* MotionBoostAction_11a000::vfunc_2(unsigned char flag) {
    volatile MotionBoostAction_11a000* self = this;
    self->mVptr = &hulk_at_0040ed10;
    RefObj_11a000* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_11a000* t2 = self->m2;
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


// 0x0011a0b0 hulkfight::ai::MotionLocatorAction::vfunc_2 (71 B): matches/0x0011a0b0.cpp
// sym: ?vfunc_2@MotionLocatorAction_11a0b0@fn_ffc509e9@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
MotionLocatorAction_11a0b0* MotionLocatorAction_11a0b0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&hulk_at_0040ed2c;
    RefCounted_11a0b0* q = *(RefCounted_11a0b0* volatile*)&m_20;
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


// 0x0011a150 hulkfight::ai::MotionFleeAction::vfunc_2 (90 B): matches/0x0011a150.cpp
// sym: ?vfunc_2@MotionFleeAction_11a150@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* MotionFleeAction_11a150::vfunc_2(unsigned char flag) {
    volatile MotionFleeAction_11a150* self = this;
    self->mVptr = &hulk_at_0040ed48;
    RefObj_11a150* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_11a150* t2 = self->m2;
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

} // namespace fn_ffc509e9

// 0x0011a1b0 hulkfight::ai::MotionClosestWaypointTrack::vfunc_10 (70 B): matches/0x0011a1b0.cpp
// sym: ?vfunc_10@MotionClosestWaypointTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::MotionClosestWaypointTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { void * a = (void *)__p0; void * b = (void *)__p1; void * p = (void *)__p2;

    int ok = ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&FightParamsType_11a1b0), (void*)(&CFightParamsType_11a1b0), 0));
    if (ok) {
        Allocated_11a1b0* x = (Allocated_11a1b0*)Allocate_0008d690(0x68);
        if (x)
            return x->Init_00117ce0(this, p);
    }
    return 0;
}


// 0x0011a250 hulkfight::ai::MotionClosestWaypointAction::vfunc_5 (1375 B): equivalent/0x0011a250.cpp [wrapped: conflict: FUN_000592a0; MotionClosestWaypointAction]
// sym: ?vfunc_5@MotionClosestWaypointAction@fn_0011a250@@UAE_NTArg1_11a250@2@M@Z @b69383e3d6f4 @w9a0c37bc77e5
namespace fn_0011a250 {
// STATUS: equivalent (tools/equiv.py level 3: 3064 inputs, branch coverage 52/56, incomplete)
// hulkfight::ai::MotionClosestWaypointAction::vfunc_5 @ 0x0011a250
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


struct Vec3_11a250 {
    float x, y, z;
    float FUN_0022d110() throw();
       // scale in place
};

struct Fighter_11a250 {
    void FUN_00059a50(Vec3_11a250 *out) throw();
};

struct Cfg2 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    char b28;
    char pad29[3];
    float f2c;
    float f30;
};

struct Ent_11a250 {
    char pad00[0x10];
    Fighter_11a250 *f10;
};

struct Hand_11a250 {
    char pad00[0x129];
    char b129;
};

class Sink_11a250 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4(Vec3_11a250 *a, Vec3_11a250 *b, struct Stats_11a250 *s, struct World *w, float dt, Vec3_11a250 *c, Vec3_11a250 *d) throw();
};

struct Stats_11a250 {
    char pad000[0x10];
    Ent_11a250 *f10dummy;
};

struct Agent;
struct World;

struct Stats2_11a250 {
    char pad000[0x10];
    Fighter_11a250 *f10;
    char pad014[0x1ca0 - 0x14];
    Hand_11a250 *f1ca0;
    Sink_11a250 *f1ca4;
    char pad1ca8[0x2064 - 0x1ca8];
    float f2064, f2068, f206c, f2070;
    void FUN_00036e70(Vec3_11a250 *p, int flag) throw();
};

Ent_11a250 *__fastcall FUN_000592a0(void *owner) throw();
Stats2_11a250 *__fastcall FUN_00059a30(Ent_11a250 *e) throw();
extern "C" float __cdecl FUN_0010b1c0(World *w, Stats2_11a250 *s, float thr, Vec3_11a250 *out) throw();
extern "C" float __cdecl FUN_000186f0(float *a, float *b) throw();

union Arg1_11a250 {
    int i;
    float f;
};

class MotionClosestWaypointAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual bool vfunc_5(Arg1_11a250 a1, float dt);
    char pad04[0x18];
    Cfg2 *f1c;
    void *f20;
    Vec3_11a250 v24;
    float f30;
    float f34;
    float f38;
    Vec3_11a250 v3c;
    char pad48[4];
    Vec3_11a250 v4c;
    char pad58[4];
    float f5c;
    float v60[2];
    char FUN_00117da0() throw();
};

bool MotionClosestWaypointAction::vfunc_5(Arg1_11a250 a1, float dt)
{
    struct Frame {
        float rmin;
        float w;
        float rmax;
        float N;
        Vec3_11a250 U;
        Vec3_11a250 P;
        Vec3_11a250 Dv;
        Vec3_11a250 W;
        Vec3_11a250 Q;
    } f;

    if (a1.i != 0)
        return true;
    if (f20 == 0)
        return false;
    Stats2_11a250 *edi = FUN_00059a30(FUN_000592a0(f20));
    f.P.x = 0.0f;
    f.P.y = 0.0f;
    f.P.z = 0.0f;
    edi->f10->FUN_00059a50(&f.P);
    f.Dv.y = 0.0f;
    f.Dv.x = v3c.x - f.P.x;
    f.Dv.z = v3c.z - f.P.z;
    f.N = -(v3c.y - f.P.y);
    float len = f.Dv.FUN_0022d110();
    a1.f = len;
    f38 = f.N;
    f34 = a1.f;
    f.U.x = 0.0f;
    f.U.y = 0.0f;
    f.U.z = 0.0f;
    Cfg2 *c = f1c;
    f.w = 0.0f;
    f.rmin = c->f18;
    f.rmax = c->f1c;
    if (a1.f < f.rmin) {
        f.U.x = f.Dv.x * -1.0f;
        f.U.y = f.Dv.y * -1.0f;
        f.U.z = f.Dv.z * -1.0f;
        f.w = c->f14;
    } else if (a1.f > f.rmax) {
        f.U = f.Dv;
        f.w = c->f14;
    }
    if (f.N < c->f20) {
        if (a1.f >= f.rmin && a1.f <= f.rmax) {
            f.U.y = 1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f < f.rmin && f.rmin > 0.0f) {
            f.U.y = 1.0f - (f.rmin - a1.f) / f.rmin;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (!(a1.f > f.rmax)) {
            f.U.y = 0.0f;
        } else {
            double r2 = f.rmax + f.rmax;   // kept on the FPU stack unrounded, like the original
            if (a1.f < r2 && f.rmax > 0.0f) {
                f.U.y = (r2 - a1.f) / r2;
                f.U.FUN_0022d110();
                f.w = f1c->f14;
            } else {
                f.U.y = 0.0f;
            }
        }
    } else if (f.N > c->f24) {
        if (a1.f >= f.rmin && a1.f <= f.rmax) {
            f.U.y = -1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f < f.rmin && f.rmin > 0.0f) {
            f.U.y = (f.rmin - a1.f) / f.rmin - 1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (!(a1.f > f.rmax)) {
            f.U.y = 0.0f;
        } else {
            double r2 = f.rmax + f.rmax;   // kept on the FPU stack unrounded, like the original
            if (a1.f < r2 && f.rmax > 0.0f) {
                f.U.y = -((r2 - a1.f) / r2);
                f.U.FUN_0022d110();
                f.w = f1c->f14;
            } else {
                f.U.y = 0.0f;
            }
        }
    }
    edi->f2064 = f.U.x;
    edi->f2068 = f.U.y;
    edi->f206c = f.U.z;
    edi->f2070 = f.w;
    if (f1c->b28 != 0 && edi->f1ca0 != 0 && edi->f1ca4 != 0) {
        f.Q.x = f.P.x;
        f.Q.y = f.P.y + 1.0f;
        f.Q.z = f.P.z;
        f.W.x = 0.0f;
        f.W.y = 0.0f;
        f.W.z = 0.0f;
        a1.f = 1.5f;
        if (edi->f1ca0->b129 == 0)
            a1.f = 0.75f;
        f.N = FUN_0010b1c0(DAT_004dd700, edi, a1.f, &f.W);
        if (f.N < 0.0f || f.N > a1.f) {
            edi->f1ca0->b129 = 0;
            f.W.z = 0.0f;
            f.W.y = 0.0f;
            f.W.x = 0.0f;
        } else {
            edi->f1ca0->b129 = 1;
            f.W.FUN_0022d110();
            a1.f = (a1.f - f.N) / a1.f;
            f.N = 1.0f;
            ((owners::Vec3_344b0 *)&(f.W))->FUN_000344b0(FUN_000186f0(&f.N, &a1.f));
        }
        edi->f1ca4->v4(&v3c, &f.Q, (Stats_11a250 *)edi, DAT_004dd700, dt, &v4c, &f.W);
    }
    f30 = f.w;
    double dx = f.P.x - v24.x;
    double dy = f.P.y - v24.y;
    double dz = f.P.z - v24.z;
    a1.f = (float)sqrt(dz * dz + dy * dy + dx * dx);
    *(unsigned int *)&a1.f &= 0x7fffffff;
    Cfg2 *c2 = f1c;
    if (a1.f / dt <= c2->f30)
        f5c = dt + f5c;
    else
        f5c = 0.0f;
    edi->FUN_00036e70((Vec3_11a250 *)v60, f5c > c2->f2c);
    v24 = f.P;
    return !FUN_00117da0();
}
} // namespace fn_0011a250
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffc509e9 {

// 0x0011a8f0 fight::ParamName<hulkfight::ai::MotionLocatorTrack>::vfunc_7 (12 B): matches/0x0011a8f0.cpp
// sym: ?vfunc_6@ParamBranch@fn_ffc509e9@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_ffc509e9

// 0x0011a960 fight::ParamName<hulkfight::ai::MotionLocatorTrack>::vfunc_0 (30 B): matches/0x0011a960.cpp
// sym: ??_G?$ParamName@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::MotionLocatorTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::MotionLocatorTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x11a960)
#endif

namespace fn_ffc509e9 {

// 0x0011a980 FUN_0011a980 (38 B): matches/0x0011a980.cpp
// sym: _FUN_0011a980
extern "C" void FUN_0011a980(Owner* owner, hulk_intptr id) {
    ConditionFactoryCasterTemplate_11a980 caster;
    void* result = Find_002343e0(id, &caster);
    owner->Set_00236760(result);
}


// 0x0011a9b0 FUN_0011a9b0 (38 B): matches/0x0011a9b0.cpp
// sym: _FUN_0011a9b0
extern "C" void FUN_0011a9b0(Obj* o, const char* s) {
    ConditionFactoryCasterTemplate_11a9b0 c;
    void* p = find_002343e0(s, &c);
    o->set_00236760(p);
}


// 0x0011a9e0 FUN_0011a9e0 (38 B): matches/0x0011a9e0.cpp
// sym: _FUN_0011a9e0
extern "C" void FUN_0011a9e0(Obj* o, void* name) {
    ConditionFactoryCasterTemplate_11a9e0 caster;
    o->use_00236760(FUN_002343e0(name, &caster));
}


// 0x0011aa10 FUN_0011aa10 (38 B): matches/0x0011aa10.cpp
// sym: _FUN_0011aa10
extern "C" void FUN_0011aa10(Owner* owner, void* name) {
    ConditionFactoryCasterTemplate_11aa10 c;
    owner->Use_00236760(Find_002343e0(name, &c));
}

} // namespace fn_ffc509e9

// 0x0011ae60 FUN_0011ae60 (281 B): equivalent/0x0011ae60.cpp [wrapped: conflict: fight::TrackFactoryCasterTemplate]
// sym: _FUN_0011ae60 @65cf0ea0459f @wb714cd8b2859
namespace fn_0011ae60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0011ae60 @ 0x0011ae60
namespace hulkfight { namespace ai { class MotionFleeTrack; class MotionStopTrack; class MotionFacingTrack; class MotionBoostTrack; class MotionLocatorTrack; class MotionTargetTrack; class MotionChaseTrack; class MotionClosestWaypointTrack; } }
namespace fight { template<class T> struct TrackFactoryCasterTemplate { virtual void create(); }; }
extern "C" void* __cdecl FUN_00236ac0(const char*, void*);
struct Registry_11ae60 { void FUN_002367c0(void*); };
extern "C" void __cdecl FUN_0011ae60(Registry_11ae60* registry) {
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack> stop;
 registry->FUN_002367c0(FUN_00236ac0("motionStop", &stop));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack> facing;
 registry->FUN_002367c0(FUN_00236ac0("motionFacing", &facing));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack> target;
 registry->FUN_002367c0(FUN_00236ac0("motionTarget", &target));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack> chase;
 registry->FUN_002367c0(FUN_00236ac0("motionChase", &chase));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack> boost;
 registry->FUN_002367c0(FUN_00236ac0("motionBoost", &boost));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack> locator;
 registry->FUN_002367c0(FUN_00236ac0("motionLocator", &locator));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack> waypoint;
 registry->FUN_002367c0(FUN_00236ac0("motionClosestWaypoint", &waypoint));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack> flee;
 registry->FUN_002367c0(FUN_00236ac0("motionFlee", &flee));
}
} // namespace fn_0011ae60


// 0x0011af80 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_1 (60 B): matches/0x0011af80.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11af80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11af80* t = new (mem) TrackFactoryTemplate_11af80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011afc0 fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_5 (48 B): matches/0x0011afc0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHasGroundPointCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_5() {
    HasGroundPointCondition_11afc0* p = (HasGroundPointCondition_11afc0*)alloc_0008d690(0x10);
    if (p) {
        ((Init_11afc0*)p)->init_00234590(0);
        *(void**)p = (void*)&hulk_at_0040eaa0;
        p->x = 1;
        p->y = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffc509e9 {

// 0x0011aff0 fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointCondition>::vfunc_2 (43 B): matches/0x0011aff0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_11aff0@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_11aff0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f2d8;
    base1_dtor_001156a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffc509e9

// 0x0011b020 fight::ConditionFactoryCasterTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_1 (60 B): matches/0x0011b020.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b020));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b020* t = new (mem) TrackFactoryTemplate_11b020();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b060 fight::ConditionFactoryTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_5 (54 B): matches/0x0011b060.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VLocatorDistanceCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_5() {
    LocatorDistanceCondition_11b060* p = (LocatorDistanceCondition_11b060*)Alloc_0008d690(0x14);
    if (p) {
        p->LocatorDistanceCondition_11b060::LocatorDistanceCondition_11b060(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040eac0);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffc509e9 {

// 0x0011b0a0 fight::ConditionFactoryTemplate<hulkfight::ai::LocatorDistanceCondition>::vfunc_2 (43 B): matches/0x0011b0a0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_11b0a0@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_11b0a0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f2f4;
    base1_dtor_00115700();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffc509e9

// 0x0011b0d0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_1 (60 B): matches/0x0011b0d0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VComputeDropZoneCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b0d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b0d0* t = new (mem) TrackFactoryTemplate_11b0d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b110 fight::ConditionFactoryTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_5 (79 B): matches/0x0011b110.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VComputeDropZoneCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_5() {
    Obj_11b110* p = (Obj_11b110*)Alloc_0008d690(0x24);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040eae0);
        *(float*)((char*)p + 12) = 15.0f;
        *(float*)((char*)p + 16) = 100.0f;
        *(float*)((char*)p + 20) = 20.0f;
        *(float*)((char*)p + 24) = 2.0f;
        *((char*)p + 28) = 0;
        *(int*)((char*)p + 32) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffc509e9 {

// 0x0011b160 fight::ConditionFactoryTemplate<hulkfight::ai::ComputeDropZoneCondition>::vfunc_2 (43 B): matches/0x0011b160.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_11b160@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_11b160::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f310;
    base1_dtor_00115770();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffc509e9

// 0x0011b190 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_1 (60 B): matches/0x0011b190.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b190));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b190* t = new (mem) TrackFactoryTemplate_11b190();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b1d0 fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_5 (87 B): matches/0x0011b1d0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VHasGroundPointExtendedCondition@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_5() {
    return (void*)(new HasGroundPointExtendedCondition_11b1d0);
}

namespace fn_ffc509e9 {

// 0x0011b230 fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_2 (43 B): matches/0x0011b230.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_11b230@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_11b230::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f32c;
    base1_dtor_001157f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffc509e9

// 0x0011b260 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_1 (60 B): matches/0x0011b260.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionFleeTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b260));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b260* t = new (mem) TrackFactoryTemplate_11b260();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b2a0 fight::TrackFactoryTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_5 (59 B): matches/0x0011b2a0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionFleeTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_5() {
    MotionFleeTrack_11b2a0* p = (MotionFleeTrack_11b2a0*)operator_new(0x18);
    if (p) {
        p->ctor_00236d40();
        p->vtable = (hulk_intptr)&hulk_at_0040eb20;
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = (int)0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_ffc509e9 {

// 0x0011b2e0 fight::TrackFactoryTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_2 (43 B): matches/0x0011b2e0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_ffc509e9@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f348;
    base1_dtor_00115880();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_ffc509e9

// 0x0011b310 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_1 (60 B): matches/0x0011b310.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionStopTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b310));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b310* t = new (mem) TrackFactoryTemplate_11b310();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b350 fight::TrackFactoryTemplate<hulkfight::ai::MotionStopTrack>::vfunc_5 (52 B): matches/0x0011b350.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionStopTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionStopTrack>::vfunc_5() {
    MotionStopTrack_11b350* p = (MotionStopTrack_11b350*)alloc_0008d690(0x14);
    if (p) {
        p->MotionStopTrack_11b350::MotionStopTrack_11b350();
        p->a = ((hulk_intptr)DAT_0040eb50);
        p->x = 0;
        p->y = -1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0011b390 fight::TrackFactoryTemplate<hulkfight::ai::MotionStopTrack>::vfunc_2 (43 B): matches/0x0011b390.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b390@@QAEPAXE@Z
namespace fn_0011b390 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f364;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115910();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f364;
    base1_dtor_00115910();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b390


// 0x0011b3c0 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_1 (60 B): matches/0x0011b3c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionFacingTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b3c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b3c0* t = new (mem) TrackFactoryTemplate_11b3c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b400 fight::TrackFactoryTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_5 (73 B): matches/0x0011b400.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionFacingTrack@ai@hulkfight@@@fight@@UAEPAXXZ
 // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_5() {
    return (void*)(new hulkfight::ai::MotionFacingTrack_11b400);
}


// 0x0011b450 fight::TrackFactoryTemplate<hulkfight::ai::MotionFacingTrack>::vfunc_2 (43 B): matches/0x0011b450.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b450@@QAEPAXE@Z
namespace fn_0011b450 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f380;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115990();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f380;
    base1_dtor_00115990();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b450


// 0x0011b480 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_1 (60 B): matches/0x0011b480.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionBoostTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b480));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b480* t = new (mem) TrackFactoryTemplate_11b480();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b4c0 fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_5 (75 B): matches/0x0011b4c0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionBoostTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_5() {
    fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>* p = (fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>*)alloc_0008d690(0x2c);
    if (p != 0) {
        ((TrackFactoryTemplate_nv_11b4c0*)(p))->initialize_00236d40();
        *(u32_11b4c0*)((char*)p + 0x0c) = 0;
        *(u32_11b4c0*)((char*)p + 0x14) = 0;
        *(u32_11b4c0*)((char*)p + 0x18) = 0;
        *(u32_11b4c0*)((char*)p + 0x1c) = 0;
        *(u32_11b4c0*)((char*)p + 0x20) = 0;
        *(u32_11b4c0*)((char*)p + 0x28) = 0;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040ebb0);
        *(u32_11b4c0*)((char*)p + 0x10) = 0xbf800000;
        *(u32_11b4c0*)((char*)p + 0x24) = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0011b510 fight::TrackFactoryTemplate<hulkfight::ai::MotionBoostTrack>::vfunc_2 (43 B): matches/0x0011b510.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b510@@QAEPAXE@Z
namespace fn_0011b510 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f39c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115a30();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f39c;
    base1_dtor_00115a30();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b510


// 0x0011b540 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_1 (60 B): matches/0x0011b540.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionTargetTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b540));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b540* t = new (mem) TrackFactoryTemplate_11b540();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b580 fight::TrackFactoryTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_5 (73 B): matches/0x0011b580.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionTargetTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_5() {
    return (void*)(new T_11b580);
}


// 0x0011b5d0 fight::TrackFactoryTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_2 (43 B): matches/0x0011b5d0.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b5d0@@QAEPAXE@Z
namespace fn_0011b5d0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f3b8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115b90();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f3b8;
    base1_dtor_00115b90();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b5d0


// 0x0011b600 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_1 (60 B): matches/0x0011b600.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionChaseTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b600));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b600* t = new (mem) TrackFactoryTemplate_11b600();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b640 fight::TrackFactoryTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_5 (75 B): matches/0x0011b640.cpp [wrapped: conflict: fight::TrackFactory; fight::TrackFactoryTemplate; hulkfight::ai::MotionChaseTrack; operatornew]
// sym: ?v5@?$TrackFactoryTemplate@VMotionChaseTrack@ai@hulkfight@fn_0011b640@@@fight@fn_0011b640@@UAEPAXXZ
namespace fn_0011b640 {
/* size_t: tree_prelude.h */

class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[8];
};
namespace hulkfight {
namespace ai {
class MotionChaseTrack : public BaseTrack {
  public:
    virtual void v0();
    int a;
    float b;
    int c, d, e, f;
    float g;
    int h;
    MotionChaseTrack() throw() : a(0), b(-1.0f), c(0), d(0), e(0), f(0), g(1.0f), h(0) {}
};
} // namespace ai
} // namespace hulkfight
namespace fight {
class TrackFactory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};
template <class T> class TrackFactoryTemplate : public TrackFactory {
  public:
    virtual void* v5();
};
} // namespace fight
template <class T> void* fight::TrackFactoryTemplate<T>::v5() {
    return new T;
}
template void* fight::TrackFactoryTemplate<hulkfight::ai::MotionChaseTrack>::v5();
} // namespace fn_0011b640


// 0x0011b690 fight::TrackFactoryTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_2 (43 B): matches/0x0011b690.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b690@@QAEPAXE@Z
namespace fn_0011b690 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f3d4;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115c30();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f3d4;
    base1_dtor_00115c30();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b690


// 0x0011b6c0 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_1 (60 B): matches/0x0011b6c0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionClosestWaypointTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b6c0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b6c0* t = new (mem) TrackFactoryTemplate_11b6c0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b720 fight::TrackFactoryTemplate<hulkfight::ai::MotionClosestWaypointTrack>::vfunc_2 (43 B): matches/0x0011b720.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b720@@QAEPAXE@Z
namespace fn_0011b720 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f3f0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115cd0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f3f0;
    base1_dtor_00115cd0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b720


// 0x0011b750 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_1 (60 B): matches/0x0011b750.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_11b750));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_11b750* t = new (mem) TrackFactoryTemplate_11b750();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0011b790 fight::TrackFactoryTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_5 (24 B): matches/0x0011b790.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VMotionLocatorTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_5() {
    Track_11b790* p = (Track_11b790*)operator_new(0x38);
    if (p)
        return (void*)(p->method_00115b00());
    return (void*)(0);
}


// 0x0011b7b0 fight::TrackFactoryTemplate<hulkfight::ai::MotionLocatorTrack>::vfunc_2 (43 B): matches/0x0011b7b0.cpp [wrapped: same definition as 0x0011b2e0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_0011b7b0@@QAEPAXE@Z
namespace fn_0011b7b0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040f40c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00115ad0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040f40c;
    base1_dtor_00115ad0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_0011b7b0

