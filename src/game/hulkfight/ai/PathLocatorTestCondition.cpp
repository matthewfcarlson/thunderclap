// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011fa30..0x00123510 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathLocatorTestCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fff5b4af {
#define TREE_TU_END }
namespace fn_fff5b4af {} using namespace fn_fff5b4af;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fff5b4af {
class Ref_11fef0 {
  public:
    virtual void Add();
    virtual void Release();
};
class Sub_11fef0 {
  public:
    void Init_0027af00();
    char d[8];
};
class Action_11fef0 {
  public:
    Action_11fef0();
    virtual void f();
    char b[0x30];
};
class RoutAction : public Action_11fef0 {
  public:
    RoutAction(int, Ref_11fef0*);
    virtual void f();
    int a34;
    Ref_11fef0* a38;
    int a3c;
    char p[0x18];
    int a58;
    int a5c;
    Sub_11fef0 s;
    char c68;
    int a6c;
    int a70;
};
extern void* hulk_at_0040f6a4[];
class Ref_11ff60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11ff60 {
  public:
    void* vptr;
};
struct Sub_11ff60 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_11ff60*) throw();
void __fastcall SubFini2(Sub_11ff60*) throw();
void __fastcall SubFini3(Sub_11ff60*) throw();
class RoutAction_11ff60 : public Action_11ff60 {
  public:
    char p34[48];
    void* m34;
    Ref_11ff60* m38;
    Ref_11ff60* m3c;
    char p60[32];
    Sub_11ff60 s60;
    ~RoutAction_11ff60() throw();
};
class CStageCondition_11fff0;
class ParamValue_11fff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_11fff0 : public ParamValue_11fff0 {
  public:
    int pad;
};
class Base {
  public:
    virtual void _m_vf0();
    Base(int);
    Base();
    char _m_pad_4[0xc];
};
class ParamEnumConstList_120000 : public Base {
  public:
    ParamEnumConstList_120000(int, int, int, int);
    int a, b, c;
};
struct CAxisArcCondition_120030;
class CStageCondition_120040 {};
class ParamValue_120040 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_120040 : public ParamValue_120040 {
  public:
    virtual void f();
};
class CStageCondition_1200d0;
class ParamValue_1200d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1200d0 : public ParamValue_1200d0 {
  public:
    int pad;
};
class CStageCondition_120120;
class ParamValue_120120 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120120 : public ParamValue_120120 {
  public:
    int pad;
};
class CStageCondition_120170;
class ParamValue_120170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120170 : public ParamValue_120170 {
  public:
    int pad;
};
class CStageCondition_1201c0;
class ParamValue_1201c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1201c0 : public ParamValue_1201c0 {
  public:
    int pad;
};
class CStageCondition_120210;
class ParamValue_120210 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120210 : public ParamValue_120210 {
  public:
    int pad;
};
class CStageCondition_120260;
class ParamValue_120260 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120260 : public ParamValue_120260 {
  public:
    int pad;
};
class CStageCondition_1202b0;
class ParamValue_1202b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1202b0 : public ParamValue_1202b0 {
  public:
    int pad;
};
class CStageCondition_120300;
class ParamValue_120300 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120300 : public ParamValue_120300 {
  public:
    int pad;
};
class CStageCondition_120350;
class ParamValue_120350 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120350 : public ParamValue_120350 {
  public:
    int pad;
};
class CStageCondition_1203a0;
class ParamValue_1203a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1203a0 : public ParamValue_1203a0 {
  public:
    int pad;
};
class CStageCondition_1203f0;
class ParamValue_1203f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1203f0 : public ParamValue_1203f0 {
  public:
    int pad;
};
class CStageCondition_120440;
class ParamValue_120440 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120440 : public ParamValue_120440 {
  public:
    int pad;
};
class CStageCondition_120490;
class ParamValue_120490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120490 : public ParamValue_120490 {
  public:
    int pad;
};
class CStageCondition_1204e0;
class ParamValue_1204e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1204e0 : public ParamValue_1204e0 {
  public:
    int pad;
};
class CStageCondition_120530;
class ParamValue_120530 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120530 : public ParamValue_120530 {
  public:
    int pad;
};
class CStageCondition_120580;
class ParamValue_120580 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_120580 : public ParamValue_120580 {
  public:
    int pad;
};
class CStageCondition_1205d0;
class ParamValue_1205d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1205d0 : public ParamValue_1205d0 {
  public:
    int pad;
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fff5b4af
namespace fight {
class ConditionFactoryCaster_120620 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class PathLocatorTestCondition_120620 {};
} }
namespace fn_fff5b4af {
extern char DAT_00491ca8;
extern char DAT_004a6590;
extern char DAT_004a66d8;
} // namespace fn_fff5b4af
namespace hulkfight { namespace ai {
class PathFormationTrack_120780;
} }
namespace fn_fff5b4af {
int __cdecl CastFunc(void*, int, void*, void*, int);
} // namespace fn_fff5b4af
namespace fight {
class TrackFactoryCaster_120780 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fight {
class TrackFactoryCaster_120820 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class StrafeRunTrack_120820 {};
} }
namespace fn_fff5b4af {
extern char DAT_004a6778;
extern char DAT_004a6820;
} // namespace fn_fff5b4af
namespace fight {
class TrackFactoryCaster_1208a0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class StrafeLateralHBTrack_1208a0 {};
} }
namespace fn_fff5b4af {
extern char DAT_004a6a10;
} // namespace fn_fff5b4af
namespace fight {
class TrackFactoryCaster_1209e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace ai {
class PathTrack_1209e0;
} }
namespace fn_fff5b4af {
extern "C" void __cdecl FUN_0011bd30();
extern "C" void __cdecl FUN_0011bd40();
extern "C" void __cdecl FUN_0011bd50();
extern "C" void __cdecl FUN_0011bd60();
extern "C" void __cdecl FUN_0011bd90();
extern "C" void __cdecl FUN_0011bdb0();
extern "C" void __cdecl FUN_0011bdd0();
extern "C" char DAT_0040f848[];
void* __cdecl alloc_0008d690(hulk_uintptr);
struct Param {
    hulk_intptr vft;
    int pad[3];
    hulk_intptr value;
};
extern "C" void __cdecl FUN_002347b0(void*, Param**, int);
extern int hulk_at_0040f5c0;
class RefObj_121f90 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class StrafeRunAction_121f90 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_121f90* m2;
    RefObj_121f90* m3;
    void* vfunc_2(unsigned char flag);
};
typedef unsigned int u32_122160;
extern int hulk_at_00494b44;
extern int hulk_at_00494b60;
struct Result_122160 {
    u32_122160 Init_0011d860(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_122160* Alloc_0008d690(int);
extern int hulk_at_0040f5dc;
class RefObj_1221b0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class StrafeCircleAction_1221b0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_1221b0* m2;
    RefObj_1221b0* m3;
    void* vfunc_2(unsigned char flag);
};
extern int hulk_at_0040f5f8;
class RefObj_122260 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class StrafeCircleHBAction_122260 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_122260* m2;
    RefObj_122260* m3;
    void* vfunc_2(unsigned char flag);
};
extern int hulk_at_0040f614;
class RefObj_122310 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class StrafeLateralHBAction_122310 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_122310* m2;
    RefObj_122310* m3;
    void* vfunc_2(unsigned char flag);
};
typedef unsigned int U_1224b0;
extern int g1_1224b0;
extern int g2_1224b0;
struct NewObj_1224b0 {
    U_1224b0 Init_0011fef0(hulkfight::ai::RoutTrack*, hulk_uintptr);
};
extern NewObj_1224b0* Allocate_0008d690(int);
class TrackFactoryCasterTemplate_122ab0 {
  public:
    virtual void fn();
};
void call_00236ac0(void*, TrackFactoryCasterTemplate_122ab0*);
class ConditionFactoryCasterTemplate_122b70 {
  public:
    virtual void Cast();
};
class Factory {
  public:
    void Add_00236760(void*);
};
extern void* Find_002343e0(const char*, ConditionFactoryCasterTemplate_122b70*);
class TrackFactoryCaster_122ba0 {
  public:
    virtual void cast();
};
class TrackFactoryCasterTemplate_122ba0 : public TrackFactoryCaster_122ba0 {
  public:
    virtual void cast();
};
class Receiver {
  public:
    void attach_002367c0(void*);
};
void* find_00236ac0(void*, TrackFactoryCaster_122ba0*);
class TrackFactoryCasterTemplate_122c30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply_002367c0(Track*);
    void Apply_002367c0(void*);
};
Track* find_00236ac0(void*, TrackFactoryCasterTemplate_122c30*);
class TrackFactoryCasterTemplate_122c60 {
  public:
    virtual void Cast();
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_122c60*);
class TrackFactoryCasterTemplate_122cc0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply_002367c0(void*);
};
extern void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_122cc0*);
} // namespace fn_fff5b4af
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fff5b4af {
class TrackFactoryTemplate_122cf0 {
  public:
    TrackFactoryTemplate_122cf0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_122d30;
struct Grapple_122d30 {
    hulk_uintptr ctor_0011c220();
};
extern void* __cdecl Alloc(hulk_uintptr);
extern int hulk_at_0040fb64;
struct ConditionFactoryTemplate_122d50 {
    void* m_vptr;
    void base1_dtor_0011c1f0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_122d80 {
  public:
    TrackFactoryTemplate_122d80() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_122dc0;
struct CAutoTargetTrack_122dc0 {
    hulk_uintptr initialize_0011c320();
};
extern int hulk_at_0040fb80;
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c2f0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_122e10 {
  public:
    TrackFactoryTemplate_122e10() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class Track_122e50 {
  public:
    hulk_intptr method_0011c3e0();
};
class TrackFactoryTemplate_122ea0 {
  public:
    TrackFactoryTemplate_122ea0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class Track_122ee0 {
  public:
    hulk_intptr method_0011c500();
};
class TrackFactoryTemplate_122f30 {
  public:
    TrackFactoryTemplate_122f30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0040f500[];
class StrafeLateralHBTrack_122f70 {
  public:
    hulk_intptr vf;
    char pad4[8];
    int zc;
    int x10;
    int z14, z18, z1c, z20, x24;
    void init_00236d40();
};
class TrackFactoryTemplate_1230b0 {
  public:
    TrackFactoryTemplate_1230b0() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
class Track_1230f0 {
  public:
    hulk_intptr method_0011c6f0();
};
class TrackFactoryTemplate_123140 {
  public:
    TrackFactoryTemplate_123140() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
typedef unsigned int u32_123180;
struct InitObj_123180 {
    hulk_uintptr Init_0011c7a0();
};
extern void* hulk_at_0040fc44[];
struct T1 {
    char c;
    void Fini_0027af50();
};
class Ref_1231d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1231d0 {
  public:
    void* vptr;
};
class PathFormationAction_1231d0 : public Action_1231d0 {
  public:
    char pad4[0x4c];
    void* m50;
    void* m54;
    char pad58[0x24];
    void* m7c;
    Ref_1231d0* m80;
    Ref_1231d0* m84;
    char pad88[4];
    void* m8c;
    void* m90;
    char pad94[0x2c];
    T1 mc0;
    ~PathFormationAction_1231d0() throw();
};
extern void* hulk_at_0040fc60[];
class Ref_123310 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_123310 {
  public:
    void* vptr;
};
class PathAction_123310 : public Action_123310 {
  public:
    char pad4[0x4c];
    void* m50;
    void* m54;
    char pad58[0x34];
    void* m8c;
    Ref_123310* m90;
    Ref_123310* m94;
    char pad98[4];
    void* m9c;
    void* ma0;
    char pada4[0x2c];
    T1 md0;
    ~PathAction_123310() throw();
};
class Sub {
  public:
    Sub();
};
class Obj_1233a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern char VT_1233a0[];
struct TypeDesc_123450 {
    int a;
    int b;
};
struct NewTrack {
    int run_00123260(hulkfight::ai::PathTrack* t, void* p);
};
extern TypeDesc_123450 typeA_123450;
extern TypeDesc_123450 typeB_123450;

} // namespace fn_fff5b4af

// 0x0011fa30 hulkfight::ai::PathLocatorTestCondition::vfunc_6 (1183 B): equivalent/0x0011fa30.cpp [wrapped: conflict: CFightParams; fight::Params; hulkfight::ai::PathLocatorTestCondition]
// sym: ?vfunc_6@PathLocatorTestCondition@ai@hulkfight@fn_0011fa30@@UAEDHTArgSlot_11fa30@4@H@Z @ee9e1b0477fa @w808b6a71a454
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0011fa30 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 70/71, incomplete)
// hulkfight::ai::PathLocatorTestCondition::vfunc_6 @ 0x0011fa30
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
extern "C" int atexit(void (*)());
#endif


struct Key_11fa30 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50();
    void FUN_0027b040(int word);
    char FUN_0027af90(Key_11fa30 *other);
};

struct V3_11fa30 {
    float x, y, z;
    hulk_freg FUN_00018990();
};

extern "C" void FUN_00363f10();

class RefCounted_11fa30 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount_11fa30 {
    char pad0[0x18];
    bool FUN_00059a50(V3_11fa30 *out);
};

struct Target_11fa30 : RefCounted_11fa30 {
    char pad04[0x3c];
    V3_11fa30 pos;
};

struct SpecialSub_11fa30 {
    char pad0[0x48];
    unsigned __int64 id;
    char padA8[0x18];
    float f0c0;
    float f0c4;
};

struct Special_11fa30 {
    char pad0[0x58];
    SpecialSub_11fa30 sub;
};

struct Stats_11fa30 {
    char pad0[0x10];
    Mount_11fa30 *mount;
    char pad14[0x328 - 0x14];
    Target_11fa30 *target;
    char pad32c[0x1ca0 - 0x32c];
    Special_11fa30 *special;
    char pad1ca4[0x1d70 - 0x1ca4];
    unsigned __int64 id1d70;
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
    virtual void v8(V3_11fa30 *out);
};

struct Registry_11fa30 {
    const char *FUN_001ff950(V3_11fa30 pos, int a, int b, float lo, float hi);
    Locator *FUN_001fc8c0(unsigned __int64 id);
};

struct World {
    char pad0[0x28];
    Registry_11fa30 *registry;
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

struct Owner_11fa30 { char pad[4]; };
Owner_11fa30 *__fastcall FUN_000592a0(void *x);
Stats_11fa30 *__fastcall FUN_00059a30(Owner_11fa30 *o);
extern "C" char __cdecl FUN_00018960(float a, float b, float eps);

union ArgSlot_11fa30 {
    fight::Params *p;
    char b;
    float f;
    int i;
};

namespace hulkfight {
namespace ai {
class PathLocatorTestCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a0, ArgSlot_11fa30 a1, int a2);
    char pad04[8];
    int name;
    unsigned int mode;
    float threshold;
    char b18;
    char b19;
    char b1a;
    char b1b;
    char b1c;
    char b1d;
    char b1e;
    char b1f;
    V3_11fa30 vec20;
};

char PathLocatorTestCondition::vfunc_6(int a0, ArgSlot_11fa30 a1, int a2)
{
    struct Frame {
        char pad10[3];
        char eq;
        union {
            Key_11fa30 t;
            V3_11fa30 tp;
            float len;
        } u;
        V3_11fa30 pos;
        V3_11fa30 d;
    } f;

    if (((*(unsigned int*)&DAT_004e0d50) & 1) == 0) {
        (*(unsigned int*)&DAT_004e0d50) |= 1;
        (*(Key_11fa30*)&DAT_004e0d48).FUN_0027af00();
        atexit(FUN_00363f10);
    }
    Registry_11fa30 *reg = DAT_004dd700->registry;
    if (reg == 0)
        return false;
    if (dynamic_cast<CFightParams *>(a1.p) == 0)
        return false;
    (*(Key_11fa30*)&DAT_004e0d48).FUN_0027b040(name);
    Stats_11fa30 *stats = FUN_00059a30(FUN_000592a0(a1.p));
    if (stats == 0)
        return false;
    f.pos.x = 0.0f;
    f.pos.y = 0.0f;
    f.pos.z = 0.0f;
    stats->mount->FUN_00059a50(&f.pos);
    Target_11fa30 *target = stats->target;

    if (!b18 && !b1e) {
        a1.b = 0;
        const char *pt = 0;
        bool query = false;
        f.u.t.FUN_0027af10((*(Key_11fa30*)&DAT_004e0ce8).lo, (*(Key_11fa30*)&DAT_004e0ce8).hi);
        f.eq = (*(Key_11fa30*)&DAT_004e0d48).FUN_0027af90(&f.u.t);
        f.u.t.FUN_0027af50();
        if (f.eq) {
            pt = reg->FUN_001ff950(f.pos, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
            query = true;
        } else {
            f.u.t.FUN_0027af10((*(Key_11fa30*)&DAT_004e0d20).lo, (*(Key_11fa30*)&DAT_004e0d20).hi);
            f.eq = (*(Key_11fa30*)&DAT_004e0d48).FUN_0027af90(&f.u.t);
            f.u.t.FUN_0027af50();
            if (f.eq) {
                if (target != 0) {
                    pt = reg->FUN_001ff950(target->pos, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
                    query = true;
                }
            } else {
                f.u.t.FUN_0027af10((*(Key_11fa30*)&DAT_004e0d00).lo, (*(Key_11fa30*)&DAT_004e0d00).hi);
                f.eq = (*(Key_11fa30*)&DAT_004e0d48).FUN_0027af90(&f.u.t);
                f.u.t.FUN_0027af50();
                if (f.eq) {
                    pt = reg->FUN_001ff950(target->pos, 2, 2, -3.40282347e+38f, 3.40282347e+38f);
                    query = true;
                }
            }
        }
        if (query && pt != 0) {
            if (reg->FUN_001fc8c0(FUN_0027b020(pt)) != 0) {
                a1.b = 1;
                return a1.b;
            }
        }
        if (!b1f)
            return a1.b;
        for (int i = 0; i < 6; i++) {
            const char *p2 = reg->FUN_001ff950(f.pos, i, 0, -vec20.y, vec20.y);
            if (p2 != 0 && reg->FUN_001fc8c0(FUN_0027b020(p2)) != 0)
                return true;
        }
        return a1.b;
    }

    Special_11fa30 *sp = stats->special;
    Registry_11fa30 *reg2 = DAT_004dd700->registry;
    Locator *loc = 0;
    if (b1b && sp != 0 && &sp->sub != 0)
        loc = reg2->FUN_001fc8c0(sp->sub.id);
    else if (b1c)
        loc = reg2->FUN_001fc8c0(stats->id1d70);
    else if (b1d)
        loc = reg2->FUN_001fc8c0(*(unsigned __int64 *)&(*(Key_11fa30*)&DAT_004e0d48));
    if (b1e)
        return loc != 0;
    a1.f = threshold;
    if (b19 && sp != 0 && &sp->sub != 0)
        a1.f = sp->sub.f0c0;
    if (b1a && sp != 0 && &sp->sub != 0)
        a1.f = sp->sub.f0c4;
    if (loc == 0)
        return false;
    loc->v8(&f.u.tp);
    f.d.x = f.u.tp.x - f.pos.x;
    f.d.y = f.u.tp.y - f.pos.y;
    f.d.z = f.u.tp.z - f.pos.z;
    f.u.len = f.d.FUN_00018990();
    unsigned int m = mode;
    if (m > 5)
        return false;
    switch (m) {
    case 0:
        return f.u.len < a1.f;
    case 1:
        return f.u.len <= a1.f;
    case 2:
        return FUN_00018960(f.u.len, a1.f, 0.00001f);
    case 3:
        return !FUN_00018960(f.u.len, a1.f, 0.00001f);
    case 4:
        return f.u.len >= a1.f;
    default:
        return f.u.len > a1.f;
    }
}
}
}
} // namespace fn_0011fa30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fff5b4af {

// 0x0011fef0 FUN_0011fef0 (98 B): matches/0x0011fef0.cpp
// sym: ??0RoutAction@fn_fff5b4af@@QAE@HPAVRef_11fef0@1@@Z
RoutAction::RoutAction(int a, Ref_11fef0* b) {
    a34 = 0;
    a38 = 0;
    a3c = 0;
    a58 = 0;
    a5c = 0;
    s.Init_0027af00();
    c68 = 0;
    a6c = 0;
    a70 = 0x43610000;
    a34 = a;
    if (b)
        b->Add();
    Ref_11fef0* o = a38;
    if (o)
        o->Release();
    a38 = b;
}


// 0x0011ff60 FUN_0011ff60 (77 B): matches/0x0011ff60.cpp
// sym: ??1RoutAction_11ff60@fn_fff5b4af@@QAE@XZ
RoutAction_11ff60::~RoutAction_11ff60() throw() {
    vptr = hulk_at_0040f6a4;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m38) {
        m38->Release();
        m38 = 0;
    }
    if (m34)
        m34 = 0;
    FUN_0027af50(&s60);
    ((fight::Action *)(Action_11ff60 *)this)->FUN_002326a0();
}

} // namespace fn_fff5b4af

// 0x0011ffd0 fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::vfunc_6 (26 B): matches/0x0011ffd0.cpp
// sym: ?vfunc_6@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::PathLocatorTestCondition>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))(b);
}


// 0x0011fff0 fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (11 B): matches/0x0011fff0.cpp
// sym: ?vfunc_2@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fff5b4af {

// 0x00120000 FUN_00120000 (46 B): matches/0x00120000.cpp
// sym: ??0ParamEnumConstList_120000@fn_fff5b4af@@QAE@HHHH@Z
ParamEnumConstList_120000::ParamEnumConstList_120000(int x, int y, int z, int w) : Base(x), a(y), b(z), c(w) {}

} // namespace fn_fff5b4af

// 0x00120030 fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_7 (6 B): matches/0x00120030.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00120040 fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_6 (30 B): matches/0x00120040.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_120040 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_120040*)&DAT_003f335c));
}


// 0x00120060 fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_8 (26 B): matches/0x00120060.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_18))(b);
}


// 0x00120080 fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (11 B): matches/0x00120080.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001200b0 fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::vfunc_6 (26 B): matches/0x001200b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))(b);
}


// 0x001200d0 fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (11 B): matches/0x001200d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120100 fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::vfunc_6 (26 B): matches/0x00120100.cpp
// sym: ?vfunc_6@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))(b);
}


// 0x00120120 fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (11 B): matches/0x00120120.cpp
// sym: ?vfunc_2@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120150 fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::vfunc_6 (26 B): matches/0x00120150.cpp
// sym: ?vfunc_6@?$ParamVector@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::**)(int))&this->f_10))(b);
}


// 0x00120170 fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (11 B): matches/0x00120170.cpp
// sym: ?vfunc_2@?$ParamVector@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001201a0 fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::vfunc_6 (26 B): matches/0x001201a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::**)(int))&this->f_10))(b);
}


// 0x001201c0 fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::vfunc_2 (11 B): matches/0x001201c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001201f0 fight::ParamBool<hulkfight::ai::RoutTrack>::vfunc_6 (26 B): matches/0x001201f0.cpp
// sym: ?vfunc_6@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::RoutTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::RoutTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::RoutTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::RoutTrack>::**)(int))&this->f_10))(b);
}


// 0x00120210 fight::ParamBool<hulkfight::ai::RoutTrack>::vfunc_2 (11 B): matches/0x00120210.cpp
// sym: ?vfunc_2@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::RoutTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120240 fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::vfunc_6 (26 B): matches/0x00120240.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))(b);
}


// 0x00120260 fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::vfunc_2 (11 B): matches/0x00120260.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120290 fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::vfunc_6 (26 B): matches/0x00120290.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VPathFormationTrack@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))(b);
}


// 0x001202b0 fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::vfunc_2 (11 B): matches/0x001202b0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VPathFormationTrack@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001202e0 fight::ParamString<hulkfight::ai::PathFormationTrack>::vfunc_6 (26 B): matches/0x001202e0.cpp
// sym: ?vfunc_6@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathFormationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::PathFormationTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::PathFormationTrack>::**)(int))&this->f_10))(b);
}


// 0x00120300 fight::ParamString<hulkfight::ai::PathFormationTrack>::vfunc_2 (11 B): matches/0x00120300.cpp
// sym: ?vfunc_2@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathFormationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120330 fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::vfunc_6 (26 B): matches/0x00120330.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::**)(int))&this->f_10))(b);
}


// 0x00120350 fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::vfunc_2 (11 B): matches/0x00120350.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120380 fight::ParamBool<hulkfight::ai::StrafeRunTrack>::vfunc_6 (26 B): matches/0x00120380.cpp
// sym: ?vfunc_6@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::StrafeRunTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::StrafeRunTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::StrafeRunTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::StrafeRunTrack>::**)(int))&this->f_10))(b);
}


// 0x001203a0 fight::ParamBool<hulkfight::ai::StrafeRunTrack>::vfunc_2 (11 B): matches/0x001203a0.cpp
// sym: ?vfunc_2@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::StrafeRunTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001203d0 fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::vfunc_6 (26 B): matches/0x001203d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::**)(int))&this->f_10))(b);
}


// 0x001203f0 fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::vfunc_2 (11 B): matches/0x001203f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120420 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::vfunc_6 (26 B): matches/0x00120420.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::**)(int))&this->f_10))(b);
}


// 0x00120440 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::vfunc_2 (11 B): matches/0x00120440.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120470 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::vfunc_6 (26 B): matches/0x00120470.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::**)(int))&this->f_10))(b);
}


// 0x00120490 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::vfunc_2 (11 B): matches/0x00120490.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001204c0 fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::vfunc_6 (26 B): matches/0x001204c0.cpp
// sym: ?vfunc_6@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::StrafeCircleTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::**)(int))&this->f_10))(b);
}


// 0x001204e0 fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::vfunc_2 (11 B): matches/0x001204e0.cpp
// sym: ?vfunc_2@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120510 fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::vfunc_6 (26 B): matches/0x00120510.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::PathTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::**)(int))&this->f_10))(b);
}


// 0x00120530 fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::vfunc_2 (11 B): matches/0x00120530.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00120560 fight::ParamString<hulkfight::ai::PathTrack>::vfunc_6 (26 B): matches/0x00120560.cpp
// sym: ?vfunc_6@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::ai::PathTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::ai::PathTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::ai::PathTrack>::**)(int))&this->f_10))(b);
}


// 0x00120580 fight::ParamString<hulkfight::ai::PathTrack>::vfunc_2 (11 B): matches/0x00120580.cpp
// sym: ?vfunc_2@?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::ai::PathTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001205b0 fight::ParamBool<hulkfight::ai::PathTrack>::vfunc_6 (26 B): matches/0x001205b0.cpp
// sym: ?vfunc_6@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PathTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::PathTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::PathTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::PathTrack>::**)(int))&this->f_10))(b);
}


// 0x001205d0 fight::ParamBool<hulkfight::ai::PathTrack>::vfunc_2 (11 B): matches/0x001205d0.cpp
// sym: ?vfunc_2@?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::PathTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_fff5b4af {

// 0x00120600 fight::ParamName<hulkfight::ai::PathTrack>::vfunc_7 (12 B): matches/0x00120600.cpp
// sym: ?vfunc_6@ParamBranch@fn_fff5b4af@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fff5b4af

// 0x00120620 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (36 B): matches/0x00120620.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004a6590, 0) != 0;
}


// 0x00120650 fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (30 B): matches/0x00120650.cpp
// sym: ??_G?$ParamString@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::PathLocatorTestCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::ai::PathLocatorTestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120650)
#endif


// 0x00120670 fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (30 B): matches/0x00120670.cpp
// sym: ??_G?$ParamEnumConstList@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::PathLocatorTestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120670)
#endif


// 0x00120690 fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (30 B): matches/0x00120690.cpp
// sym: ??_G?$ParamFloatConstRange@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::PathLocatorTestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120690)
#endif


// 0x001206b0 fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (30 B): matches/0x001206b0.cpp
// sym: ??_G?$ParamBool@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::PathLocatorTestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1206b0)
#endif


// 0x001206d0 fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::vfunc_0 (30 B): matches/0x001206d0.cpp
// sym: ??_G?$ParamVector@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::PathLocatorTestCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1206d0)
#endif


// 0x00120700 fight::TrackFactoryCasterTemplate<hulkfight::ai::RoutTrack>::vfunc_0 (36 B): matches/0x00120700.cpp [wrapped: conflict: a; check; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate (+1)]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VRoutTrack@ai@hulkfight@fn_00120700@@@fight@fn_00120700@@UAE_NPAX@Z
namespace fn_00120700 {
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
namespace ai {
class RoutTrack {};
} // namespace ai
} // namespace hulkfight
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, void*, void*, int);
extern int hulk_at_0049850c, hulk_at_004a6638;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::RoutTrack>::vfunc_0(void* p) {
    return check(p, 0, &hulk_at_0049850c, &hulk_at_004a6638, 0) != 0;
}
} // namespace fn_00120700


// 0x00120730 fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::vfunc_0 (30 B): matches/0x00120730.cpp
// sym: ??_G?$ParamFloatConstRange@VRoutTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::RoutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120730)
#endif


// 0x00120750 fight::ParamBool<hulkfight::ai::RoutTrack>::vfunc_0 (30 B): matches/0x00120750.cpp
// sym: ??_G?$ParamBool@VRoutTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::RoutTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::RoutTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120750)
#endif


// 0x00120780 fight::TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_0 (36 B): matches/0x00120780.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPathFormationTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastFunc(p, 0, (void*)&DAT_0049850c, (void*)&DAT_004a66d8, 0) != 0;
}


// 0x001207b0 fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::vfunc_0 (30 B): matches/0x001207b0.cpp
// sym: ??_G?$ParamFloatConstRange@VPathFormationTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::PathFormationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1207b0)
#endif


// 0x001207d0 fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::vfunc_0 (30 B): matches/0x001207d0.cpp
// sym: ??_G?$ParamIntConstRange@VPathFormationTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::PathFormationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1207d0)
#endif


// 0x001207f0 fight::ParamString<hulkfight::ai::PathFormationTrack>::vfunc_0 (30 B): matches/0x001207f0.cpp
// sym: ??_G?$ParamString@VPathFormationTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::PathFormationTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::ai::PathFormationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1207f0)
#endif


// 0x00120820 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_0 (36 B): matches/0x00120820.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStrafeRunTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a6778, 0) != 0;
}


// 0x00120850 fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::vfunc_0 (30 B): matches/0x00120850.cpp
// sym: ??_G?$ParamFloatConstRange@VStrafeRunTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::StrafeRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120850)
#endif


// 0x00120870 fight::ParamBool<hulkfight::ai::StrafeRunTrack>::vfunc_0 (30 B): matches/0x00120870.cpp
// sym: ??_G?$ParamBool@VStrafeRunTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::StrafeRunTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::StrafeRunTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120870)
#endif


// 0x001208a0 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_0 (36 B): matches/0x001208a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VStrafeLateralHBTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a6820, 0) != 0;
}


// 0x001208d0 fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::vfunc_0 (30 B): matches/0x001208d0.cpp
// sym: ??_G?$ParamFloatConstRange@VStrafeLateralHBTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::StrafeLateralHBTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1208d0)
#endif


// 0x00120900 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleHBTrack>::vfunc_0 (36 B): matches/0x00120900.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?vfunc_0@TrackFactoryCasterTemplate@fight@fn_00120900@@UAE_NPAX@Z
namespace fn_00120900 {
struct Info {
    int value;
};
extern Info a, hulk_at_004a68c8;
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return check(p, 0, &a, &hulk_at_004a68c8, 0) != 0;
}
} // namespace fn_00120900


// 0x00120930 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::vfunc_0 (30 B): matches/0x00120930.cpp
// sym: ??_G?$ParamFloatConstRange@VStrafeCircleHBTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleHBTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120930)
#endif


// 0x00120960 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_0 (36 B): matches/0x00120960.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::ai::StrafeCircleTrack]
// sym: ?cast@?$TrackFactoryCasterTemplate@VStrafeCircleTrack@ai@hulkfight@fn_00120960@@@fight@fn_00120960@@UAEHPAX@Z
namespace fn_00120960 {
struct Info {};
extern Info a, hulk_at_004a6970;
extern "C++" __declspec(nothrow) int __cdecl check(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int cast(void*);
    virtual void other();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int cast(void*);
    virtual void other();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeCircleTrack {};
} // namespace ai
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleTrack>::cast(void* p) {
    return check(p, 0, &a, &hulk_at_004a6970, 0) != 0;
}
} // namespace fn_00120960


// 0x00120990 fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::vfunc_0 (30 B): matches/0x00120990.cpp
// sym: ??_G?$ParamFloatConstRange@VStrafeCircleTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::StrafeCircleTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120990)
#endif


// 0x001209b0 fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::vfunc_0 (30 B): matches/0x001209b0.cpp
// sym: ??_G?$ParamBool@VStrafeCircleTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::StrafeCircleTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::StrafeCircleTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1209b0)
#endif


// 0x001209e0 fight::TrackFactoryCasterTemplate<hulkfight::ai::PathTrack>::vfunc_0 (36 B): matches/0x001209e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPathTrack@ai@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::PathTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a6a10, 0) != 0;
}


// 0x00120a10 fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::vfunc_0 (30 B): matches/0x00120a10.cpp
// sym: ??_G?$ParamFloatConstRange@VPathTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::PathTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::PathTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120a10)
#endif


// 0x00120a30 fight::ParamString<hulkfight::ai::PathTrack>::vfunc_0 (30 B): matches/0x00120a30.cpp
// sym: ??_G?$ParamString@VPathTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::PathTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::ai::PathTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120a30)
#endif


// 0x00120a50 fight::ParamBool<hulkfight::ai::PathTrack>::vfunc_0 (30 B): matches/0x00120a50.cpp
// sym: ??_G?$ParamBool@VPathTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::PathTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::PathTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120a50)
#endif


// 0x00120a70 fight::ParamName<hulkfight::ai::PathTrack>::vfunc_0 (30 B): matches/0x00120a70.cpp
// sym: ??_G?$ParamName@VPathTrack@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::ai::PathTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::ai::PathTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x120a70)
#endif

namespace fn_fff5b4af {

// 0x001214f0 FUN_001214f0 (409 B): matches/0x001214f0.cpp
// sym: ?target@fn_fff5b4af@@YAXXZ
// data: counter = DAT_004e0ccc, registry_1214f0 = DAT_004e0cc8
void target() {
    if ((*(int*)&DAT_004e0ccc) == 0) {
        Param* list[7];
        Param* p;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeBegin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd30);
            list[0] = p;
        } else
            list[0] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeEnd");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd40);
            list[1] = p;
        } else
            list[1] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("distance");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd50);
            list[2] = p;
        } else
            list[2] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("turnRate");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd60);
            list[3] = p;
        } else
            list[3] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("heightMin");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bd90);
            list[4] = p;
        } else
            list[4] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("heightMax");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdb0);
            list[5] = p;
        } else
            list[5] = 0;
        p = (Param*)alloc_0008d690(0x18);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("speed");
            p->vft = ((hulk_intptr)DAT_0040f848);
            p->value = ((hulk_intptr)(void (__cdecl*)())&FUN_0011bdd0);
            list[6] = p;
        } else
            list[6] = 0;
        FUN_002347b0(((void**)&DAT_004e0cc8), list, 7);
    }
    ++(*(int*)&DAT_004e0ccc);
}


// 0x00121f90 hulkfight::ai::StrafeRunAction::vfunc_2 (90 B): matches/0x00121f90.cpp
// sym: ?vfunc_2@StrafeRunAction_121f90@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* StrafeRunAction_121f90::vfunc_2(unsigned char flag) {
    volatile StrafeRunAction_121f90* self = this;
    self->mVptr = &hulk_at_0040f5c0;
    RefObj_121f90* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_121f90* t2 = self->m2;
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

} // namespace fn_fff5b4af

// 0x00121ff0 hulkfight::ai::PathFormationAction::vfunc_3 (364 B): equivalent/0x00121ff0.cpp [wrapped: conflict: FUN_000592a0; World]
// sym: ?vfunc_3@PathFormationAction@fn_00121ff0@@UAE_NHH@Z @1dd1b47de81a @w28118b725e12
namespace fn_00121ff0 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 16/16)
// hulkfight::ai::PathFormationAction::vfunc_3 @ 0x00121ff0
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

struct Fighter_121ff0 { char pad[4]; };

struct Holder_121ff0 {
    char pad0[0x380];
    int value;
};

struct Stats_121ff0 {
    char pad0[0x11c];
    Holder_121ff0 *holder;
};

Fighter_121ff0 *__fastcall FUN_000592a0(void *owner);
Stats_121ff0 *__fastcall FUN_00059a30(Fighter_121ff0 *f);

struct Item_121ff0 {
    unsigned char active;
    char pad1[3];
    int f20, f24, f28, f2c, f30, f34;
};

struct ResourceName_121ff0 {
    char data[8];
};

struct Pair_121ff0 {
    int a;
    int b;
};

struct StatsBlock {
    char pad0[8];
    int a;
    int b;
};

struct Settings_121ff0 {
    char pad0[0x150];
    int level;
    char pad154[0x2cc - 0x154];
    int value;
    void FUN_00065dd0(const Pair_121ff0 *p);
};
Settings_121ff0 *__cdecl FUN_000678d0();

struct Owner_121ff0 {
    char pad0[0x2c];
    int count;
    char pad30[4];
    const char *name;
};

struct Ring_121ff0 {
    Item_121ff0 **first;
    Item_121ff0 **last;
    Item_121ff0 **buff;
    Item_121ff0 **end;
};

struct Queue_121ff0 {
    char pad0[0x18];
    Ring_121ff0 ring;
};

struct World {
    char pad0[0x1c];
    Queue_121ff0 *queue;
};

class PathFormationAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Item_121ff0 item;
    float f38;
    float f3c;
    float f40;
    float f44;
    int f48;
    char pad4c[0x64 - 0x4c];
    int f64, f68, f6c, f70;
    int f74;
    int f78;
    Owner_121ff0 *owner;
    void *fighterOwner;
    char pad84[0xa0 - 0x84];
    int fa0, fa4, fa8, fac, fb0, fb4;
    Stats_121ff0 *stats;
    char padbc[4];
    ResourceName_121ff0 name;
};

bool PathFormationAction::vfunc_3(int a, int b)
{
    if (fighterOwner == 0)
        return false;
    fa0 = 0; fa4 = 0; fa8 = 0; fac = 0; fb0 = 0; fb4 = 0;
    item.active = 0;
    item.f20 = 0; item.f24 = 0; item.f28 = 0; item.f2c = 0; item.f30 = 0; item.f34 = 0;
    Fighter_121ff0 *fighter = FUN_000592a0(fighterOwner);
    Stats_121ff0 *s = FUN_00059a30(fighter);
    stats = s;
    if (s != 0) {
        Holder_121ff0 *h = s->holder;
        if (h != 0)
            f78 = h->value;
    }
    f3c = 0.2f;
    f38 = 1.0f;
    f40 = 1.0f;
    f44 = 0.3f;
    f48 = 0;
    f64 = 0; f68 = 0; f6c = 0; f70 = 0;
    f74 = 2;

    Ring_121ff0 *r = &DAT_004dd700->queue->ring;
    if (r->last < r->end) {
        if (r->last != 0)
            *r->last = &item;
        Item_121ff0 **end = r->end;
        r->last = r->last + 1;
        if (r->last == end)
            r->last = r->buff;
        if (r->first == r->last)
            r->last = r->last + (end - r->buff);
    }

    ((owners::Target_27b040 *)&name)->FUN_0027b040((hulk_uintptr)(owner->name));
    Stats_121ff0 *s2 = FUN_00059a30(fighter);
    int count = owner->count;
    FUN_000678d0()->value = count;
    if (FUN_000678d0()->level < owner->count) {
        StatsBlock *sb = (StatsBlock *)s2;
        Pair_121ff0 p;
        p.a = sb->a;
        p.b = sb->b;
        FUN_000678d0()->FUN_00065dd0(&p);
    }
    return true;
}
} // namespace fn_00121ff0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00122160 hulkfight::ai::StrafeCircleTrack::vfunc_10 (70 B): matches/0x00122160.cpp
// sym: ?vfunc_10@StrafeCircleTrack@ai@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::ai::StrafeCircleTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_122160 a = (u32_122160)__p0; u32_122160 b = (u32_122160)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        Result_122160* q = Alloc_0008d690(0x28);
        if (q)
            return (int)(q->Init_0011d860(this, p));
    }
    return (int)(0);
}

namespace fn_fff5b4af {

// 0x001221b0 hulkfight::ai::StrafeCircleAction::vfunc_2 (90 B): matches/0x001221b0.cpp
// sym: ?vfunc_2@StrafeCircleAction_1221b0@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* StrafeCircleAction_1221b0::vfunc_2(unsigned char flag) {
    volatile StrafeCircleAction_1221b0* self = this;
    self->mVptr = &hulk_at_0040f5dc;
    RefObj_1221b0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_1221b0* t2 = self->m2;
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


// 0x00122260 hulkfight::ai::StrafeCircleHBAction::vfunc_2 (90 B): matches/0x00122260.cpp
// sym: ?vfunc_2@StrafeCircleHBAction_122260@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* StrafeCircleHBAction_122260::vfunc_2(unsigned char flag) {
    volatile StrafeCircleHBAction_122260* self = this;
    self->mVptr = &hulk_at_0040f5f8;
    RefObj_122260* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_122260* t2 = self->m2;
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


// 0x00122310 hulkfight::ai::StrafeLateralHBAction::vfunc_2 (90 B): matches/0x00122310.cpp
// sym: ?vfunc_2@StrafeLateralHBAction_122310@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* StrafeLateralHBAction_122310::vfunc_2(unsigned char flag) {
    volatile StrafeLateralHBAction_122310* self = this;
    self->mVptr = &hulk_at_0040f614;
    RefObj_122310* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_122310* t2 = self->m2;
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

} // namespace fn_fff5b4af

// 0x00122370 hulkfight::ai::PathAction::vfunc_3 (313 B): equivalent/0x00122370.cpp [wrapped: conflict: World]
// sym: ?run@PathAction@fn_00122370@@QAE_NHH@Z @23c41b4e278e @w4861d45cf950
namespace fn_00122370 {
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 12/12)
// hulkfight::ai::PathAction::vfunc_3 @ 0x00122370
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

struct Zone_122370 { char pad[0x380]; int value; };
struct ZoneRef { char pad[0x11c]; Zone_122370* zone; };
struct Node { ZoneRef* FUN_00059a30(); };
struct Owner_122370 {  };

struct Ring_122370 {
    void** head;
    void** cur;
    void** begin;
    void** limit;
};

struct Listeners {
    char pad[0x18];
    Ring_122370 ring;
};

struct World {
    char pad[0x1c];
    Listeners* listeners;
    char pad2[0x28 - 0x20];
    int stamp;
};

struct Source_122370 {
    char pad[0x38];
    int id;
};

struct Sub_122370 {
    char pad[0x10];
};


class PathAction {
public:
    bool run(int a, int b);
    char p0[0x1c];
    char c1c;
    char p1[3];
    int w20[6];
    float f38;
    float f3c;
    float f40;
    float f44;
    int w48;
    char p2[0x64 - 0x4c];
    int w64[4];
    int w74;
    int w78;
    int w7c;
    int w80;
    int w84;
    int w88;
    Source_122370* src8c;
    Owner_122370* owner90;
    char p3[0xb0 - 0x94];
    int wb0[6];
    ZoneRef* zoneRef;
    char p4[4];
    Sub_122370 sub;
    int stamp;
    int we4;
    char p6[4];
    int wec;
};

bool PathAction::run(int a, int b)
{
    w7c = -1;
    wec = 0;
    for (int i = 0; i < 6; i++)
        wb0[i] = 0;
    we4 = 0;
    c1c = 0;
    for (int i = 0; i < 6; i++)
        w20[i] = 0;

    zoneRef = ((Node *)((owners::Object_592a0 *)owner90)->FUN_000592a0())->FUN_00059a30();
    if (zoneRef != 0) {
        if (zoneRef->zone != 0)
            w78 = zoneRef->zone->value;
    }
    f3c = 0.2f;
    f38 = 1.0f;
    f40 = 1.0f;
    f44 = 0.3f;
    w48 = 0;
    for (int i = 0; i < 4; i++)
        w64[i] = 0;
    w74 = 2;

    Ring_122370* ring = &DAT_004dd700->listeners->ring;
    if (ring->cur < ring->limit) {
        if (ring->cur != 0)
            *ring->cur = &c1c;
        ring->cur = ring->cur + 1;
        void** limit = ring->limit;
        if (ring->cur == limit)
            ring->cur = ring->begin;
        if (ring->head == ring->cur)
            ring->cur = ring->cur + (((char*)limit - (char*)ring->begin) >> 2);
    }

    ((owners::Target_27b040 *)&sub)->FUN_0027b040((hulk_uintptr)(src8c->id));
    stamp = DAT_004dd700->stamp;
    w88 = 0;
    w84 = 0;
    w80 = 0;
    return true;
}
} // namespace fn_00122370
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001224b0 hulkfight::ai::RoutTrack::vfunc_10 (73 B): matches/0x001224b0.cpp
// sym: ?vfunc_10@RoutTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::RoutTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { U_1224b0 a = (U_1224b0)__p0; U_1224b0 b = (U_1224b0)__p1; hulk_uintptr c = (U_1224b0)__p2;

    if (IsType((void*)c, 0, &g1_1224b0, &g2_1224b0, 0)) {
        NewObj_1224b0* p = Allocate_0008d690(0xb8);
        if (p)
            return (int)(p->Init_0011fef0(this, c));
    }
    return (int)(0);
}


// 0x00122500 hulkfight::ai::RoutAction::vfunc_2 (30 B): matches/0x00122500.cpp
// sym: ??_GRoutAction@ai@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::ai::RoutAction::~RoutAction() {}


// 0x00122520 hulkfight::ai::RoutAction::vfunc_5 (1352 B): equivalent/0x00122520.cpp [wrapped: conflict: DAT_004dd700; FUN_000592a0; RoutAction]
// sym: ?vfunc_5@RoutAction@fn_00122520@@UAE_NTArg1_122520@2@M@Z @3dc40fdf58fb @wafb84cf3a124
namespace fn_00122520 {
// STATUS: equivalent (tools/equiv.py level 3: 3098 inputs, branch coverage 50/51, incomplete)
// hulkfight::ai::RoutAction::vfunc_5 @ 0x00122520


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_122520 {
    float x, y, z;
    float FUN_000111f0() throw();
    float FUN_0022d110() throw();
    float FUN_00018990() throw();
       // scale in place
};

struct Key_122520 {
    unsigned int lo, hi;
    void FUN_0027af00() throw();
};

struct Mat_122520 {
    float m[16];
};

struct World;

struct Fighter_122520 {
    void FUN_00059a50(Vec3_122520 *out) throw();
};

struct Ent_122520 {
    char pad00[0x10];
    Fighter_122520 *f10;
};

class RefObj_122520 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
    char pad04[4];
    Ent_122520 *f08;
    int f0c;
};

struct Hand_122520 {
    char pad[0x129];
    char b129;
};

struct Sub_122520 {
    char pad000[0x10c];
    Vec3_122520 v10c;
    float f118;
    Vec3_122520 v11c;
    void FUN_00060170() throw();
};

struct Stats_122520;

class Sink_122520 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual char v4(Vec3_122520 *a, Vec3_122520 *b, Stats_122520 *s, World *w, float dt, void *c, Vec3_122520 *d) throw();
    char FUN_0010aa90(World *w, Vec3_122520 *b, Vec3_122520 *a, float k, Vec3_122520 *o1, Vec3_122520 *o2, Vec3_122520 *r, Stats_122520 *s, RefObj_122520 *obj, int p, int q) throw();
};

struct Stats_122520 {
    char pad000[0x10];
    Fighter_122520 *f10;
    char pad014[0x328 - 0x14];
    RefObj_122520 *f328;
    char pad32c[0x1ca0 - 0x32c];
    Hand_122520 *f1ca0;
    Sink_122520 *f1ca4;
    char pad1ca8[0x1f58 - 0x1ca8];
    Sub_122520 sub1f58;
    void FUN_00035160(Mat_122520 *m) throw();
};

struct Cfg_122520 {
    char pad00[0x18];
    float f18;
    char pad1c[4];
    float f20;
    float f24;
    char b28;
    char pad29[3];
    float f2c;
    float f30;
    float f34;
};


#define DAT_004dd700 (*(World * *)&::DAT_004dd700)

extern "C" void FUN_00363f20();
extern "C" float __cdecl FUN_0010b1c0(World *w, Stats_122520 *s, float thr, Vec3_122520 *out) throw();
extern "C" float __cdecl FUN_000186f0(float *a, float *b) throw();
extern "C" Vec3_122520 *__cdecl FUN_00083e00(Vec3_122520 *out, Vec3_122520 *a, float c) throw();
void __cdecl FUN_00224d70(float angle, Vec3_122520 *v) throw();
Ent_122520 *__fastcall FUN_000592a0(void *owner) throw();

union Arg1_122520 {
    int i;
    float f;
};

class RoutAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual bool vfunc_5(Arg1_122520 a1, float dt);
    char pad04[0x18];
    Vec3_122520 v1c;
    Vec3_122520 v28;
    Cfg_122520 *f34;
    RefObj_122520 *f38;
    RefObj_122520 *f3c;
    char pad40[0x58 - 0x40];
    float f58;
    Stats_122520 *f5c;
    char pad60[0x6c - 0x60];
    float f6c;
    float f70;
    Mat_122520 m74;
};

bool RoutAction::vfunc_5(Arg1_122520 a1, float dt)
{
    struct Frame {
        float thr;
        union {
            Hand_122520 *h;
            float r;
            float one;
            float pz;
        } u4;
        union {
            World *world;
            float c18;
            float c34;
            float q;
        } u8;
        Vec3_122520 D;
        Vec3_122520 P;
        Vec3_122520 Out;
        Vec3_122520 W;
        Vec3_122520 B;
        Vec3_122520 A;
        Vec3_122520 R;
        Vec3_122520 X60;
        Vec3_122520 Y6c;
    } f;

    f.u8.world = DAT_004dd700;
    if (!(DAT_004e0d60 & 1)) {
        DAT_004e0d60 |= 1;
        (*(Key_122520*)((char*)&DAT_004e0d50 + 8)).FUN_0027af00();
        atexit(FUN_00363f20);
    }
    f6c = dt + f6c;
    if (a1.i != 0)
        return true;
    if (f38 == 0)
        return false;
    Stats_122520 *stats = f5c;
    if (stats == 0)
        return false;
    f.u4.h = stats->f1ca0;
    RefObj_122520 *obj = stats->f328;
    if (obj == 0) {
        obj = f3c;
        if (obj == 0)
            return true;
    }
    obj->AddRef();
    if (f3c != 0)
        f3c->Release();
    f3c = obj;
    if (obj == 0)
        return false;
    if (obj->f0c != 1)
        return false;
    Ent_122520 *tgt = obj->f08;
    if (tgt == 0)
        return false;
    stats = f5c;
    Sub_122520 *edi = (Sub_122520 *)((char *)stats + 0x1f58);
    if (edi == 0)
        return false;
    stats->FUN_00035160(&m74);
    f5c->f10->FUN_00059a50(&f.P);
    tgt->f10->FUN_00059a50(&f.D);
    f.D.x = f.D.x - f.P.x;
    f.D.y = f.D.y - f.P.y;
    f.D.z = f.D.z - f.P.z;
    ((owners::C_35660 *)tgt)->FUN_00035660((int *)(Vec3_122520 *)(&f.X60));
    float len = f.D.FUN_000111f0();
    if (len < f70) {
        double k = -1.0f / sqrt(len);
        f.R.x = 0.0f;
        f.R.y = 0.0f;
        f.R.z = 1.0f;
        f.D.x = f.D.x * k;
        f.D.y = f.D.y * k;
        f.D.z = f.D.z * k;
        ((owners::M_22c3b0 *)&m74)->FUN_0022c3b0((float *)(Vec3_122520 *)(&f.R), (float *)(Vec3_122520 *)(&f.Out));
        float dotF = f.Out.y * f.D.y + f.D.z * f.Out.z + f.Out.x * f.D.x;
        if (dotF > -0.99f) {
            float cross = f.Out.z * f.D.x - f.Out.x * f.D.z;
            if (cross > 0.0f)
                FUN_00224d70(-180.0f, &f.Out);
            else
                FUN_00224d70(180.0f, &f.Out);
        }
        edi->v11c = f.Out;
        edi->v10c = f.Out;
        edi->f118 = f34->f18;
    } else {
        edi->FUN_00060170();
    }
    Hand_122520 *h = f.u4.h;
    f.W.x = 0.0f;
    f.W.y = 0.0f;
    f.W.z = 0.0f;
    if (h != 0 && f34->b28 != 0) {
        if (h->b129 != 0)
            f.thr = f34->f30;
        else
            f.thr = f34->f2c;
        f.u4.r = FUN_0010b1c0(f.u8.world, f5c, f.thr, &f.W);
        if (f.u4.r < 0.0f || f.u4.r > f.thr) {
            h->b129 = 0;
            f.W.z = 0.0f;
            f.W.y = 0.0f;
            f.W.x = 0.0f;
        } else {
            h->b129 = 1;
            f.W.FUN_0022d110();
            f.u8.q = (f.thr - f.u4.r) / f.thr;
            f.u4.one = 1.0f;
            // The scale factor is pushed before ecx is set, so it is one expression: the
            // receiver is the whole vector W (the shifted lea made it look like &W.y).
            ((owners::Vec3_344b0 *)&(f.W))->FUN_000344b0(FUN_000186f0(&f.u4.one, &f.u8.q));
        }
    }
    Cfg_122520 *cfg = f34;
    f.u8.c34 = cfg->f34;
    Vec3_122520 *res = FUN_00083e00(&f.R, &edi->v10c, cfg->f34);
    f.u4.pz = f.P.z + res->z;
    f.B.y = f.P.y;
    f.A.z = f.u4.pz;
    f.A.x = f.P.x + res->x;
    f.B.z = f.P.z;
    f.A.y = (f.P.y + res->y) + 1.0f;
    f.B.x = f.P.x;
    f.B.y = f.B.y + 1.0f;
    f.u8.c18 = cfg->f18;
    if (edi->f118 != 0.0f && f5c->f1ca4 != 0 && cfg->b28 != 0) {
        f.R.x = f.A.x - f.B.x;
        f.R.y = f.A.y - f.B.y;
        f.R.z = f.u4.pz - f.B.z;
        if (!f5c->f1ca4->FUN_0010aa90(DAT_004dd700, &f.B, &f.A, 1.0f, &f.Y6c, &f.Out, &f.R, f5c, obj, 1, 1)) {
            edi->FUN_00060170();
        } else if (!f5c->f1ca4->v4(&f.A, &f.B, f5c, DAT_004dd700, dt, &v1c, &f.W)) {
            edi->f118 = f.u8.c18;
        }
    }
    f.R.x = f.P.x - v28.x;
    f.R.y = f.P.y - v28.y;
    f.R.z = f.P.z - v28.z;
    f.u8.q = f.R.FUN_00018990();
    *(unsigned int *)&f.u8.q &= 0x7fffffff;
    Cfg_122520 *c = f34;
    if (f.u8.q / dt <= c->f24)
        f58 = dt + f58;
    else
        f58 = 0.0f;
    if (f58 > c->f20)
        return false;
    v28 = f.P;
    return true;
}
} // namespace fn_00122520
#undef DAT_004dd700

namespace fn_fff5b4af {

// 0x00122ab0 FUN_00122ab0 (27 B): matches/0x00122ab0.cpp
// sym: ?target@fn_fff5b4af@@YAXPAX@Z
void target(void* p) {
    TrackFactoryCasterTemplate_122ab0 c;
    call_00236ac0(p, &c);
}


// 0x00122b70 FUN_00122b70 (38 B): matches/0x00122b70.cpp
// sym: _FUN_00122b70
extern "C" void FUN_00122b70(Factory* f, const char* name) {
    ConditionFactoryCasterTemplate_122b70 caster;
    f->Add_00236760(Find_002343e0(name, &caster));
}


// 0x00122ba0 FUN_00122ba0 (38 B): matches/0x00122ba0.cpp
// sym: _FUN_00122ba0
extern "C" void FUN_00122ba0(Receiver* r, void* obj) {
    TrackFactoryCasterTemplate_122ba0 caster;
    r->attach_002367c0(find_00236ac0(obj, &caster));
}

} // namespace fn_fff5b4af

// 0x00122bd0 FUN_00122bd0 (38 B): matches/0x00122bd0.cpp [wrapped: conflict: Find]
// sym: _FUN_00122bd0
namespace fn_00122bd0 {
class TrackFactoryCasterTemplate_122bd0 {
  public:
    virtual void Check();
};
class Obj {
  public:
    void Apply_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(void*, TrackFactoryCasterTemplate_122bd0*);
extern "C" void FUN_00122bd0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_122bd0 c;
    obj->Apply_002367c0(Find_00236ac0(name, &c));
}
} // namespace fn_00122bd0


// 0x00122c00 FUN_00122c00 (38 B): matches/0x00122c00.cpp [wrapped: conflict: Find]
// sym: _FUN_00122c00
namespace fn_00122c00 {
class TrackFactoryCasterTemplate_122c00 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* Find_00236ac0(const char*, TrackFactoryCasterTemplate_122c00*);
extern "C" void FUN_00122c00(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_122c00 caster;
    owner->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_00122c00

namespace fn_fff5b4af {

// 0x00122c30 FUN_00122c30 (38 B): matches/0x00122c30.cpp
// sym: _FUN_00122c30
extern "C" void FUN_00122c30(Obj* o, void* name) {
    TrackFactoryCasterTemplate_122c30 c;
    Track* p = find_00236ac0(name, &c);
    o->apply_002367c0(p);
}


// 0x00122c60 FUN_00122c60 (38 B): matches/0x00122c60.cpp
// sym: _FUN_00122c60
extern "C" void FUN_00122c60(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_122c60 caster;
    void* found = Lookup(key, &caster);
    obj->Apply_002367c0(found);
}

} // namespace fn_fff5b4af

// 0x00122c90 FUN_00122c90 (38 B): matches/0x00122c90.cpp [wrapped: conflict: Lookup]
// sym: _FUN_00122c90
namespace fn_00122c90 {
class TrackFactoryCasterTemplate_122c90 {
  public:
    virtual void Cast();
};
extern "C++" __declspec(nothrow) void* Lookup_00236ac0(void*, TrackFactoryCasterTemplate_122c90*);
class Target {
  public:
    void Set_002367c0(void*);
};
extern "C" void FUN_00122c90(Target* t, void* key) {
    TrackFactoryCasterTemplate_122c90 caster;
    t->Set_002367c0(Lookup_00236ac0(key, &caster));
}
} // namespace fn_00122c90

namespace fn_fff5b4af {

// 0x00122cc0 FUN_00122cc0 (38 B): matches/0x00122cc0.cpp
// sym: _FUN_00122cc0
extern "C" void FUN_00122cc0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_122cc0 caster;
    owner->Apply_002367c0(Find_00236ac0(name, &caster));
}

} // namespace fn_fff5b4af

// 0x00122cf0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_1 (60 B): matches/0x00122cf0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_122cf0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_122cf0* t = new (mem) TrackFactoryTemplate_122cf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00122d30 fight::ConditionFactoryTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_5 (24 B): matches/0x00122d30.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPathLocatorTestCondition@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f850 (propagated; names are from that function)
template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_5() {
    Grapple_122d30* p = (Grapple_122d30*)Alloc_0008d690(0x2c);
    if (p)
        return (void*)(p->ctor_0011c220());
    return (void*)(0);
}

namespace fn_fff5b4af {

// 0x00122d50 fight::ConditionFactoryTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_2 (43 B): matches/0x00122d50.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_122d50@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_122d50::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fb64;
    base1_dtor_0011c1f0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fff5b4af

// 0x00122d80 fight::TrackFactoryCasterTemplate<hulkfight::ai::RoutTrack>::vfunc_1 (60 B): matches/0x00122d80.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VRoutTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::RoutTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_122d80));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_122d80* t = new (mem) TrackFactoryTemplate_122d80();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00122dc0 fight::TrackFactoryTemplate<hulkfight::ai::RoutTrack>::vfunc_5 (24 B): matches/0x00122dc0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VRoutTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00075d20 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::RoutTrack>::vfunc_5() {
    CAutoTargetTrack_122dc0* p = (CAutoTargetTrack_122dc0*)alloc_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize_0011c320());
    return (void*)(0);
}

namespace fn_fff5b4af {

// 0x00122de0 fight::TrackFactoryTemplate<hulkfight::ai::RoutTrack>::vfunc_2 (43 B): matches/0x00122de0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fff5b4af@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fb80;
    base1_dtor_0011c2f0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fff5b4af

// 0x00122e10 fight::TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_1 (60 B): matches/0x00122e10.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPathFormationTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::PathFormationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_122e10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_122e10* t = new (mem) TrackFactoryTemplate_122e10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00122e50 fight::TrackFactoryTemplate<hulkfight::ai::PathFormationTrack>::vfunc_5 (24 B): matches/0x00122e50.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPathFormationTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::PathFormationTrack>::vfunc_5() {
    Track_122e50* p = (Track_122e50*)operator_new(0x38);
    if (p)
        return (void*)(p->method_0011c3e0());
    return (void*)(0);
}


// 0x00122e70 fight::TrackFactoryTemplate<hulkfight::ai::PathFormationTrack>::vfunc_2 (43 B): matches/0x00122e70.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00122e70@@QAEPAXE@Z
namespace fn_00122e70 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fb9c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c3b0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fb9c;
    base1_dtor_0011c3b0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00122e70


// 0x00122ea0 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_1 (60 B): matches/0x00122ea0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStrafeRunTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_122ea0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_122ea0* t = new (mem) TrackFactoryTemplate_122ea0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00122ee0 fight::TrackFactoryTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_5 (24 B): matches/0x00122ee0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStrafeRunTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_5() {
    Track_122ee0* p = (Track_122ee0*)operator_new(0x38);
    if (p)
        return (void*)(p->method_0011c500());
    return (void*)(0);
}


// 0x00122f00 fight::TrackFactoryTemplate<hulkfight::ai::StrafeRunTrack>::vfunc_2 (43 B): matches/0x00122f00.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00122f00@@QAEPAXE@Z
namespace fn_00122f00 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fbb8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c4d0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fbb8;
    base1_dtor_0011c4d0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00122f00


// 0x00122f30 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_1 (60 B): matches/0x00122f30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStrafeLateralHBTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_122f30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_122f30* t = new (mem) TrackFactoryTemplate_122f30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00122f70 fight::TrackFactoryTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_5 (72 B): matches/0x00122f70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStrafeLateralHBTrack@ai@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_5() {
    StrafeLateralHBTrack_122f70* p = (StrafeLateralHBTrack_122f70*)operator_new(0x28);
    if (p) {
        p->init_00236d40();
        p->zc = 0;
        p->z14 = 0;
        p->z18 = 0;
        p->z1c = 0;
        p->z20 = 0;
        p->vf = ((hulk_intptr)DAT_0040f500);
        p->x10 = (int)0xbf800000;
        p->x24 = 0x3f800000;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00122fc0 fight::TrackFactoryTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_2 (43 B): matches/0x00122fc0.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00122fc0@@QAEPAXE@Z
namespace fn_00122fc0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fbd4;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c580();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fbd4;
    base1_dtor_0011c580();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00122fc0


// 0x00122ff0 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleHBTrack>::vfunc_1 (60 B): matches/0x00122ff0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate]
// sym: ?f1@?$TrackFactoryCasterTemplate@VStrafeCircleHBTrack@ai@hulkfight@fn_00122ff0@@@fight@fn_00122ff0@@UAEPAXH@Z
void* __cdecl operator new(size_t);
namespace fn_00122ff0 {
/* size_t: tree_prelude.h */

extern "C" void __cdecl FUN_00121690();
class Base {
  public:
    Base() throw();
    virtual void f();
    int v;
};
class Elem {
  public:
    Elem(int) throw();
    int x, y;
};
class Obj : public Base {
  public:
    Obj(int n) throw() : elem(n) {}
    virtual void f();
    Elem elem;
};
namespace fight {
class TrackFactoryCaster {
  public:
    virtual void f0();
    virtual void* f1(int);
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual void* f1(int);
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeCircleHBTrack;
}
} // namespace hulkfight
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleHBTrack>::f1(int a) {
    Obj* p = new Obj(a);
    if (p)
        FUN_00121690();
    return p;
}
} // namespace fn_00122ff0


// 0x00123080 fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleHBTrack>::vfunc_2 (43 B): matches/0x00123080.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00123080@@QAEPAXE@Z
namespace fn_00123080 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fbf0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c620();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fbf0;
    base1_dtor_0011c620();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00123080


// 0x001230b0 fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_1 (60 B): matches/0x001230b0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VStrafeCircleTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1230b0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1230b0* t = new (mem) TrackFactoryTemplate_1230b0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001230f0 fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_5 (24 B): matches/0x001230f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VStrafeCircleTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006fac0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_5() {
    Track_1230f0* p = (Track_1230f0*)operator_new(0x38);
    if (p)
        return (void*)(p->method_0011c6f0());
    return (void*)(0);
}


// 0x00123110 fight::TrackFactoryTemplate<hulkfight::ai::StrafeCircleTrack>::vfunc_2 (43 B): matches/0x00123110.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00123110@@QAEPAXE@Z
namespace fn_00123110 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fc0c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c6c0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fc0c;
    base1_dtor_0011c6c0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00123110


// 0x00123140 fight::TrackFactoryCasterTemplate<hulkfight::ai::PathTrack>::vfunc_1 (60 B): matches/0x00123140.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPathTrack@ai@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::ai::PathTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_123140));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_123140* t = new (mem) TrackFactoryTemplate_123140();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00123180 fight::TrackFactoryTemplate<hulkfight::ai::PathTrack>::vfunc_5 (24 B): matches/0x00123180.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPathTrack@ai@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f220 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::PathTrack>::vfunc_5() {
    void* p = Alloc_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_123180*)p)->Init_0011c7a0());
    return (void*)(0);
}


// 0x001231a0 fight::TrackFactoryTemplate<hulkfight::ai::PathTrack>::vfunc_2 (43 B): matches/0x001231a0.cpp [wrapped: same definition as 0x00122de0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001231a0@@QAEPAXE@Z
namespace fn_001231a0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0040fc28;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_0011c770();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0040fc28;
    base1_dtor_0011c770();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001231a0

namespace fn_fff5b4af {

// 0x001231d0 FUN_001231d0 (136 B): matches/0x001231d0.cpp
// sym: ??1PathFormationAction_1231d0@fn_fff5b4af@@QAE@XZ
PathFormationAction_1231d0::~PathFormationAction_1231d0() throw() {
    vptr = hulk_at_0040fc44;
    _ReadWriteBarrier();
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m80) {
        m80->Release();
        m80 = 0;
    }
    if (m7c)
        m7c = 0;
    mc0.Fini_0027af50();
    void* p = m8c;
    m90 = p;
    if (p)
        operator delete[](p);
    p = m50;
    m54 = p;
    if (p)
        operator delete[](p);
    ((fight::Action *)(Action_1231d0 *)this)->FUN_002326a0();
}

} // namespace fn_fff5b4af

// 0x00123260 FUN_00123260 (167 B): equivalent/0x00123260.cpp [wrapped: conflict: PathAction]
// sym: ?FUN_00123260@PathAction@fn_00123260@@QAEPAU12@HPAURefObj_123260@2@@Z @a8addbc320bb @w4da8e03b2d93
namespace fn_00123260 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00123260 @ 0x00123260
extern "C" char DAT_0040fc60[];

struct RefObj_123260 {
    virtual void addRef();
    virtual void release();
};
struct Name_123260 {
    char data[8];
    void FUN_0027af00();
};

struct PathAction {
    hulk_intptr vptr;
    char pad04[0x4c];
    int f50;
    int f54;
    int f58;
    char pad5c[4];
    int f60;
    char pad64[0x7c - 0x64];
    int f7c;
    char pad80[0x8c - 0x80];
    int f8c;
    RefObj_123260 *f90;
    int f94;
    char pad98[4];
    int f9c;
    int fa0;
    int fa4;
    char padA8[4];
    int fac;
    char padB0[0xd0 - 0xb0];
    Name_123260 name;                  // 0xd0
    char fd8;
    char padD9[3];
    int fdc;
    char padE0[8];
    int fe8;
    int fec;
    void FUN_00232660();
    PathAction *FUN_00123260(int a, RefObj_123260 *target);
};

PathAction *PathAction::FUN_00123260(int a, RefObj_123260 *target)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_0040fc60;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    f60 = 0;
    f7c = -1;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    fac = 0;
    name.FUN_0027af00();
    fd8 = 0;
    fdc = 0;
    fe8 = 0;
    fec = 0;
    f8c = a;
    if (target)
        target->addRef();
    if (f90)
        f90->release();
    f90 = target;
    return this;
}
} // namespace fn_00123260

namespace fn_fff5b4af {

// 0x00123310 FUN_00123310 (142 B): matches/0x00123310.cpp
// sym: ??1PathAction_123310@fn_fff5b4af@@QAE@XZ
PathAction_123310::~PathAction_123310() throw() {
    vptr = hulk_at_0040fc60;
    _ReadWriteBarrier();
    if (m94) {
        m94->Release();
        m94 = 0;
    }
    if (m90) {
        m90->Release();
        m90 = 0;
    }
    if (m8c)
        m8c = 0;
    md0.Fini_0027af50();
    void* p = m9c;
    ma0 = p;
    if (p)
        operator delete[](p);
    p = m50;
    m54 = p;
    if (p)
        operator delete[](p);
    ((fight::Action *)(Action_123310 *)this)->FUN_002326a0();
}

} // namespace fn_fff5b4af

// 0x001233a0 FUN_001233a0 (142 B): matches/0x001233a0.cpp
// sym: ?FUN_001233a0@PathFormationAction@ai@hulkfight@@QAEPAV123@HPAX@Z
hulkfight::ai::PathFormationAction* hulkfight::ai::PathFormationAction::FUN_001233a0(int a, void* __p1) { Obj_1233a0 * b = (Obj_1233a0 *)__p1;

    char* p = (char*)this;
    ((Base*)this)->Base::Base();
    *(void**)p = VT_1233a0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x54) = 0;
    *(int*)(p + 0x58) = 0;
    *(int*)(p + 0x60) = 0;
    *(int*)(p + 0x7c) = 0;
    *(int*)(p + 0x80) = 0;
    *(int*)(p + 0x84) = 0;
    *(int*)(p + 0x8c) = 0;
    *(int*)(p + 0x90) = 0;
    *(int*)(p + 0x94) = 0;
    _ReadWriteBarrier();
    *(int*)(p + 0x9c) = 0;
    ((Sub*)(p + 0xc0))->Sub::Sub();
    *(char*)(p + 0xc8) = 0;
    *(int*)(p + 0xcc) = 0;
    *(int*)(p + 0x7c) = a;
    if (b)
        b->AddRef();
    Obj_1233a0* old = *(Obj_1233a0**)(p + 0x80);
    if (old)
        old->Release();
    *(Obj_1233a0**)(p + 0x80) = b;
    return (PathFormationAction*)(this);
}


// 0x00123430 hulkfight::ai::PathFormationAction::vfunc_2 (30 B): matches/0x00123430.cpp
// sym: ??_GPathFormationAction@ai@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::ai::PathFormationAction::~PathFormationAction() {}


// 0x00123450 hulkfight::ai::PathTrack::vfunc_10 (73 B): matches/0x00123450.cpp
// sym: ?vfunc_10@PathTrack@ai@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::ai::PathTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { void * p = (void *)__p2;

    if (TypeCheck(p, 0, &typeA_123450, &typeB_123450, 0)) {
        NewTrack* q = (NewTrack*)Alloc_0008d690(0xf0);
        if (q)
            return q->run_00123260(this, p);
    }
    return 0;
}


// 0x001234a0 hulkfight::ai::PathAction::vfunc_2 (30 B): matches/0x001234a0.cpp
// sym: ??_GPathAction@ai@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::ai::PathAction::~PathAction() {}

