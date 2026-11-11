// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00125820..0x00127290 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetArcCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f038364c {
#define TREE_TU_END }
namespace fn_f038364c {} using namespace fn_f038364c;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f038364c {
struct V3_1260a0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Anchor_1260a0 {
    char FUN_00059a50(V3_1260a0 *out);
};
struct Target_1260a0 {
    char pad0[0x40];
    V3_1260a0 pos;
    char pad4c[4];
    V3_1260a0 dir;
};
struct Fighter_1260a0 {
    char pad0[0x10];
    Anchor_1260a0 *anchor;
    char pad14[0x328 - 0x14];
    Target_1260a0 *target;
};
struct Chain_1260a0 {
    Fighter_1260a0 *FUN_00059a30();
};
} // namespace fn_f038364c
namespace fight {
class Params_1260a0 {
public:
    virtual void v0();
    Chain_1260a0 *FUN_000592a0();
};
}
namespace fn_f038364c {
class CFightParams_1260a0 : public fight::Params_1260a0 {
public:
    virtual void v0();
};
bool FUN_00018960(float a, float b, float eps);
} // namespace fn_f038364c
namespace fight {
class Condition_1260a0 {
public:
    virtual void c0();
};
}
namespace fn_f038364c {
struct V3_126270 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Anchor_126270 {
    char FUN_00059a50(V3_126270 *out);
};
struct Target_126270 {
    char pad0[0x40];
    V3_126270 pos;
    char pad4c[4];
    V3_126270 dir;
};
struct Fighter_126270 {
    char pad0[0x10];
    Anchor_126270 *anchor;
    char pad14[0x328 - 0x14];
    Target_126270 *target;
};
struct Chain_126270 {
    Fighter_126270 *FUN_00059a30();
};
} // namespace fn_f038364c
namespace fight {
class Params_126270 {
public:
    virtual void v0();
    Chain_126270 *FUN_000592a0();
};
}
namespace fn_f038364c {
class CFightParams_126270 : public fight::Params_126270 {
public:
    virtual void v0();
};
} // namespace fn_f038364c
namespace fight {
class Condition_126270 {
public:
    virtual void c0();
};
}
namespace fn_f038364c {
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct Vec3_126450 {
    float x, y, z;
};
struct Locator_126450 {
    void FUN_00059a50(Vec3_126450 *out);
};
struct Target_126450 {
    char pad0[0x40];
    Vec3_126450 pos;
    char pad4c[0x54 - 0x4c];
    float scale;
};
struct Actor_126450 {
    char pad0[0x10];
    Locator_126450 *locator;
    char pad14[0x328 - 0x14];
    Target_126450 *target;
};
struct Chain_126450 {
    Actor_126450 *FUN_00059a30();
};
struct Owner_126450 {
};
extern double __cdecl FUN_000189c0(float v);
struct Vec3_1265c0 {
    float x, y, z;
};
struct Body_1265c0 {
    char pad00[0x40];
    Vec3_1265c0 pos;
};
struct Holder_1265c0 {
    char pad00[0x10];
    void *f10;
};
struct Locator_1265c0;
struct Locator_1265c0 {
    char FUN_00059a50(Vec3_1265c0 *out);
};
struct Res_1265c0 {
    char pad00[0x10];
    Locator_1265c0 *loc;
    char pad14[0x328 - 0x14];
    Body_1265c0 *body;
};
struct Resolver_1265c0 {
    Res_1265c0 *FUN_00059a30();
};
struct Target_1265c0 {
};
hulk_freg __fastcall FUN_0022d110(Vec3_1265c0 *v);
class RefObj_126780 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_126780 {
  public:
    Action_126780();
    virtual void Update();
    char pad[0x18];
};
class AcquireTargetAction_126780 : public Action_126780 {
  public:
    int mTarget;
    RefObj_126780* mObj;
    AcquireTargetAction_126780(int target, RefObj_126780* obj);
    virtual void Execute();
};
extern void* hulk_at_00410004[];
class Ref_1267d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1267d0 {
  public:
    void* vptr;
};
class AcquireTargetAction_1267d0 : public Action_1267d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1267d0* m20;
    ~AcquireTargetAction_1267d0();
};
class RefObj_126810 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_126810 {
  public:
    Action_126810();
    virtual void Update();
    char pad[0x18];
};
class ClearProjectileDistanceAction_126810 : public Action_126810 {
  public:
    int mTarget;
    RefObj_126810* mObj;
    ClearProjectileDistanceAction_126810(int target, RefObj_126810* obj);
    virtual void Execute();
};
extern void* hulk_at_00410020[];
class Ref_126860 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_126860 {
  public:
    void* vptr;
};
class ClearProjectileDistanceAction_126860 : public Action_126860 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_126860* m20;
    ~ClearProjectileDistanceAction_126860();
};
class RefObj_1268a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1268a0 {
  public:
    Action_1268a0();
    virtual void Update();
    char pad[0x18];
};
class TargetClearAction_1268a0 : public Action_1268a0 {
  public:
    int mTarget;
    RefObj_1268a0* mObj;
    TargetClearAction_1268a0(int target, RefObj_1268a0* obj);
    virtual void Execute();
};
extern void* hulk_at_0041003c[];
class Ref_1268f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1268f0 {
  public:
    void* vptr;
};
class TargetClearAction_1268f0 : public Action_1268f0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1268f0* m20;
    ~TargetClearAction_1268f0();
};
class ParamValueEnum_126930 {
  public:
    virtual void f();
    char pad[12];
    ParamValueEnum_126930(int);
};
class ParamEnumConstList_126930 : public ParamValueEnum_126930 {
  public:
    virtual void f();
    int a, b, c;
    ParamEnumConstList_126930(int, int, int, int);
};
struct CAxisArcCondition_126960;
class CStageCondition_126970 {};
class ParamValue_126970 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126970 : public ParamValue_126970 {
  public:
    virtual void f();
};
class CStageCondition_126a00;
class ParamValue_126a00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126a00 : public ParamValue_126a00 {
  public:
    int pad;
};
class CStageCondition_126a50;
class ParamValue_126a50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126a50 : public ParamValue_126a50 {
  public:
    int pad;
};
class CStageCondition_126aa0;
class ParamValue_126aa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126aa0 : public ParamValue_126aa0 {
  public:
    int pad;
};
class CStageCondition_126af0;
class ParamValue_126af0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126af0 : public ParamValue_126af0 {
  public:
    int pad;
};
struct CAxisArcCondition_126b30;
class CStageCondition_126b40 {};
class ParamValue_126b40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126b40 : public ParamValue_126b40 {
  public:
    virtual void f();
};
struct CAxisArcCondition_126bc0;
class CStageCondition_126bd0 {};
class ParamValue_126bd0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126bd0 : public ParamValue_126bd0 {
  public:
    virtual void f();
};
class CStageCondition_126c60;
class ParamValue_126c60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126c60 : public ParamValue_126c60 {
  public:
    int pad;
};
class CStageCondition_126cb0;
class ParamValue_126cb0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126cb0 : public ParamValue_126cb0 {
  public:
    int pad;
};
struct CAxisArcCondition_126cf0;
class CStageCondition_126d00 {};
class ParamValue_126d00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126d00 : public ParamValue_126d00 {
  public:
    virtual void f();
};
class CStageCondition_126d90;
class ParamValue_126d90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126d90 : public ParamValue_126d90 {
  public:
    int pad;
};
struct CAxisArcCondition_126dd0;
class CStageCondition_126de0 {};
class ParamValue_126de0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126de0 : public ParamValue_126de0 {
  public:
    virtual void f();
};
class CStageCondition_126e70;
class ParamValue_126e70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126e70 : public ParamValue_126e70 {
  public:
    int pad;
};
struct CAxisArcCondition_126eb0;
class CStageCondition_126ec0 {};
class ParamValue_126ec0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_126ec0 : public ParamValue_126ec0 {
  public:
    virtual void f();
};
class CStageCondition_126f50;
class ParamValue_126f50 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126f50 : public ParamValue_126f50 {
  public:
    int pad;
};
class CStageCondition_126fa0;
class ParamValue_126fa0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126fa0 : public ParamValue_126fa0 {
  public:
    int pad;
};
class CStageCondition_126ff0;
class ParamValue_126ff0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_126ff0 : public ParamValue_126ff0 {
  public:
    int pad;
};
struct CAxisArcCondition_127030;
class CStageCondition_127040 {};
class ParamValue_127040 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_127040 : public ParamValue_127040 {
  public:
    virtual void f();
};
class CStageCondition_1270d0;
class ParamValue_1270d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1270d0 : public ParamValue_1270d0 {
  public:
    int pad;
};
class CStageCondition_127120;
class ParamValue_127120 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127120 : public ParamValue_127120 {
  public:
    int pad;
};
class CStageCondition_127170;
class ParamValue_127170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127170 : public ParamValue_127170 {
  public:
    int pad;
};
struct CAxisArcCondition_1271b0;
class CStageCondition_1271c0 {};
class ParamValue_1271c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1271c0 : public ParamValue_1271c0 {
  public:
    virtual void f();
};
class CStageCondition_127250;
class ParamValue_127250 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_127250 : public ParamValue_127250 {
  public:
    int pad;
};

} // namespace fn_f038364c

// 0x00125820 hulkfight::ai::TargetDistanceYCondition::vfunc_6 (382 B): equivalent/0x00125820.cpp [wrapped: conflict: FUN_00018960]
// sym: ?vfunc_6@TargetDistanceYCondition@fn_00125820@@UAEDHPAUOwner_125820@2@H@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00125820 {
// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 27/30, incomplete)
// hulkfight::ai::TargetDistanceYCondition::vfunc_6 @ 0x00125820
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

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float epsilon);

union FloatBits_125820 {
    float f;
    unsigned int u;
};

struct Vec3_125820 {
    float x, y, z;
};

struct TargetObj {
    char pad0[0x1a60];
    float x;
    float y;
    float z;
};

struct Target_125820 {
    char pad0[8];
    TargetObj *obj;
    int kind;
    char pad10[0x30];
    Vec3_125820 pos;
};

struct Locator {
    char pad0[0x12c];
    Target_125820 *target;
};

struct Slot_125820 {
    char pad0[0x124];
    Locator *locator;
};

struct World {
    char pad0[0x20];
    Slot_125820 *slot;
};


struct Position_125820 {
    void FUN_00059a50(Vec3_125820 *out);
};

struct Actor_125820 {
    char pad0[0x10];
    Position_125820 *position;
    char pad14[0x314];
    Target_125820 *target;
};

struct Chain_125820 {
    Actor_125820 *FUN_00059a30();
};

struct Owner_125820 {
};

class TargetDistanceYCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_125820 *owner, int unused3);
    char pad4[8];
    int mode;
    float threshold;
    char absolute;
    char useLocator;
    char useObj;
};

char TargetDistanceYCondition::vfunc_6(int unused1, Owner_125820 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor_125820 *actor = ((Chain_125820 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    Vec3_125820 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    actor->position->FUN_00059a50(&origin);
    Target_125820 *t = actor->target;
    if (useLocator) {
        Locator *loc = DAT_004dd700->slot->locator;
        if (loc)
            t = loc->target;
    }
    if (!t)
        return 0;
    float ty;
    if (t->kind == 1 && t->obj && useObj)
        ty = t->obj->y;
    else
        ty = t->pos.y;
    float dist = ty - origin.y;
    if (absolute == 1) {
        FloatBits_125820 bits;
        bits.f = dist;
        bits.u &= 0x7fffffff;
        dist = bits.f;
    }
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
} // namespace fn_00125820
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001259c0 hulkfight::ai::TargetOrientationCondition::vfunc_6 (207 B): equivalent/0x001259c0.cpp [wrapped: conflict: DAT_00494b44; hulkfight::ai::TargetOrientationCondition]
// sym: ?vfunc_6@TargetOrientationCondition@ai@hulkfight@fn_001259c0@@UAE_NHPAUInput_1259c0@4@H@Z
namespace fn_001259c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 10/10)
// hulkfight::ai::TargetOrientationCondition::vfunc_6 @ 0x001259c0

struct Vec_1259c0 { float x,y,z; void FUN_0022c3b0(const Vec_1259c0*, Vec_1259c0*); };
extern char DAT_00494b44, DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern hulk_freg __cdecl FUN_00224f10(Vec_1259c0*);
extern hulk_freg __cdecl FUN_00224fc0(float, float);
struct Target_1259c0 { char pad[16]; Vec_1259c0 position; };
struct Link_1259c0 { char pad[0x12c]; Target_1259c0* target; };
struct Actor_1259c0 { char pad[0x328]; Target_1259c0* fallback; char gap[4]; Link_1259c0* link; };
struct Heading_1259c0 { hulk_freg FUN_000354c0(); };
struct Context { Actor_1259c0* FUN_00059a30(); };
struct Input_1259c0 { Context* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct TargetOrientationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int, Input_1259c0*, int);
 char pad[8]; float offset; float range;
};
bool TargetOrientationCondition::vfunc_6(int, Input_1259c0* input, int) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_1259c0* actor=input->FUN_000592a0()->FUN_00059a30();
 Target_1259c0* target=0;
 if(actor->link) target=actor->link->target;
 if(!target) target=actor->fallback;
 if(!target) return false;
 Vec_1259c0 direction;
 target->position.FUN_0022c3b0(((Vec_1259c0*)&DAT_004a6ae4),&direction);
 float angle=FUN_00224f10(&direction);
 float delta=FUN_00224fc0(((Heading_1259c0*)actor)->FUN_000354c0()+offset,angle);
 union { float f; unsigned int u; } absolute;
 absolute.f=delta; absolute.u &= 0x7fffffff;
 return range*0.5f > absolute.f;
}
}}
} // namespace fn_001259c0


// 0x00125a90 hulkfight::ai::TargetArcCondition::vfunc_6 (583 B): equivalent/0x00125a90.cpp [wrapped: conflict: CFightParams; World; fight::Params; hulkfight::ai::TargetArcCondition]
// sym: ?vfunc_6@TargetArcCondition@ai@hulkfight@fn_00125a90@@UAE_NHPAVParams@fight@4@H@Z
namespace fn_00125a90 {
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 25/26, incomplete)
// hulkfight::ai::TargetArcCondition::vfunc_6 @ 0x00125a90
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

struct V3_125a90 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct M4_125a90 {
    float m[16];
    void FUN_0022c3b0(V3_125a90* in, V3_125a90* out);
};

struct Entity {
    char pad00[0x40];
    V3_125a90 pos;                     // 0x40
};

struct Mount_125a90 {
    void FUN_00059a50(V3_125a90* out);
};

struct Finder_125a90 {
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad00[8];
    Finder_125a90* finder;             // 0x08
    char pad0c[0x1c - 0xc];
    M4_125a90* matrices;               // 0x1c
};

struct Fighter_125a90 {
    char pad00[0x12c];
    Entity* lock;               // 0x12c
};

struct Stats_125a90 {
    char pad00[0x10];
    Mount_125a90* mount;               // 0x10
    char pad14[0x120 - 0x14];
    Skeleton* skeleton;         // 0x120
    char pad124[0x328 - 0x124];
    Entity* target;             // 0x328
    char pad32c[0x330 - 0x32c];
    Fighter_125a90* fighter;           // 0x330
    char pad334[4];
    int f338;                   // 0x338
    hulk_freg FUN_000354c0();
};

struct Handle_125a90 {
    Stats_125a90* FUN_00059a30();
};

struct Owner_125a90 {
    char pad00[0x124];
    Fighter_125a90* current;           // 0x124
};

struct World {
    char pad00[0x20];
    Owner_125a90* owner;               // 0x20
};

struct Singleton_125a90 {
    V3_125a90* FUN_001c39c0();
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_125a90* FUN_000592a0();
};

extern "C" Singleton_125a90* FUN_001c3d90();
hulk_freg FUN_00224f10(V3_125a90* v);
hulk_freg FUN_00224fc0(float a, float b);
hulk_freg FUN_00018a20(float v);

namespace hulkfight {
namespace ai {
class TargetArcCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, fight::Params* params, int a3);

    char pad04[8];
    float f0c;
    float f10;                  // 0x10: half-arc
    char b14;                   // 0x14
    char pad15[3];
    unsigned int idLo;          // 0x18
    unsigned int idHi;          // 0x1c
    V3_125a90 offset;                  // 0x20
    char b2c;                   // 0x2c
};

bool TargetArcCondition::vfunc_6(int a1, fight::Params* params, int a3)
{
    if (!dynamic_cast<CFightParams*>(params))
        return false;

    Stats_125a90* stats = ((CFightParams*)params)->FUN_000592a0()->FUN_00059a30();
    V3_125a90 dir;
    if (b14) {
        dir = *FUN_001c3d90()->FUN_001c39c0();
    } else {
        Fighter_125a90* holder;
        Entity* e;
        bool viaHolder;
        if (b2c) {
            holder = DAT_004dd700->owner->current;
            viaHolder = holder != 0;
        } else {
            holder = stats->fighter;
            viaHolder = holder != 0 && stats->f338 == 0;
        }
        e = 0;
        if (viaHolder)
            e = holder->lock;
        if (!e) {
            e = stats->target;
            if (!e)
                return false;
        }
        V3_125a90 pos;
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        stats->mount->FUN_00059a50(&pos);
        V3_125a90 t = e->pos;
        dir.x = t.x - pos.x;
        dir.y = t.y - pos.y;
        dir.z = t.z - pos.z;
    }

    float angle = FUN_00224f10(&dir);
    float diff;
    if ((idLo | idHi) == 0) {
        diff = FUN_00224fc0(stats->FUN_000354c0() + f0c, angle);
    } else {
        Skeleton* skel = stats->skeleton;
        int idx = 0;
        if (skel) {
            idx = skel->finder->FUN_0027b200(idLo, idHi);
            if (idx == 0xffff)
                idx = 0;
        }
        V3_125a90 d2;
        d2.x = 0.0f;
        d2.y = 0.0f;
        d2.z = -1.0f;
        if (skel) {
            M4_125a90 mx = skel->matrices[idx];
            V3_125a90 tv = offset;
            mx.FUN_0022c3b0(&tv, &d2);
            d2.FUN_0022d110();
        }
        dir.FUN_0022d110();
        diff = FUN_00018a20(d2.z * dir.z + d2.y * dir.y + d2.x * dir.x);
    }

    union { float f; unsigned int u; } ad;
    ad.f = diff;
    ad.u &= 0x7fffffff;
    return f10 * 0.5f > ad.f;
}
}
}
} // namespace fn_00125a90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00125ce0 hulkfight::ai::TargetVelocityCondition::vfunc_6 (321 B): equivalent/0x00125ce0.cpp [wrapped: conflict: CFightParams; FUN_00018960; fight::Params]
// sym: ?vfunc_6@TargetVelocityCondition@fn_00125ce0@@UAEDHPAVParams@fight@2@H@Z
namespace fn_00125ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3206 inputs, branch coverage 18/18; Wine build 679 inputs, 18/18)
// hulkfight::ai::TargetVelocityCondition::vfunc_6 @ 0x00125ce0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


struct Vec3_125ce0 { float x, y, z; };

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

struct Owner_125ce0 {
    char pad[0x328];
    struct Body_125ce0 *body;
};
struct Body_125ce0 {
    char pad[0x50];
    Vec3_125ce0 velocity;
};

class Context { public: char pad[4]; };

Context *__fastcall FUN_000592a0(void *obj);
extern "C" Owner_125ce0 *__fastcall FUN_00059a30(Context *ctx);
int __cdecl FUN_00018960(float a, float b, float c);

class TargetVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight::Params *params, int c);
    char pad04[8];
    int mode;
    float threshold;
};

char TargetVelocityCondition::vfunc_6(int a, fight::Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    Owner_125ce0 *owner = FUN_00059a30(FUN_000592a0(params));
    Body_125ce0 *body = owner->body;
    if (body == 0)
        return 0;
    Vec3_125ce0 v = body->velocity;
    float len = (float)sqrt(v.z * v.z + v.x * v.x + v.y * v.y);
    switch (mode) {
    case 0: return len < threshold;
    case 1: return len <= threshold;
    case 2: return (char)FUN_00018960(len, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(len, threshold, 1e-5f) == 0;
    case 4: return len >= threshold;
    case 5: return len > threshold;
    }
    return 0;
}
} // namespace fn_00125ce0


// 0x00125e40 hulkfight::ai::TargetVelocityXZCondition::vfunc_6 (311 B): equivalent/0x00125e40.cpp [wrapped: conflict: FUN_00018960]
// sym: ?vfunc_6@TargetVelocityXZCondition@fn_00125e40@@UAEDHPAUOwner_125e40@2@H@Z
namespace fn_00125e40 {
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 18/18)
// hulkfight::ai::TargetVelocityXZCondition::vfunc_6 @ 0x00125e40

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float epsilon);

struct Vec3_125e40 {
    float x, y, z;
};

struct Body_125e40 {
    char pad0[0x328];
    char *pad328;
};

struct Velocity_125e40 {
    char pad0[0x50];
    Vec3_125e40 value;
};

struct Actor_125e40 {
    char pad0[0x328];
    Velocity_125e40 *target;
};

struct Chain_125e40 {
    Actor_125e40 *FUN_00059a30();
};

struct Owner_125e40 {
};

class TargetVelocityXZCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_125e40 *owner, int unused3);
    char pad4[8];
    int mode;
    float threshold;
};

char TargetVelocityXZCondition::vfunc_6(int unused1, Owner_125e40 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Velocity_125e40 *v = ((Chain_125e40 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30()->target;
    if (!v)
        return 0;

    float x = v->value.x;
    float z = v->value.z;
    float speed = (float)sqrt((double)(x * x + z * z));
    switch (mode) {
    case 0:
        return speed < threshold;
    case 1:
        return speed <= threshold;
    case 2:
        return FUN_00018960(speed, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(speed, threshold, 1e-5f);
    case 4:
        return speed >= threshold;
    case 5:
        return speed > threshold;
    }
    return 0;
}
} // namespace fn_00125e40


// 0x00125f90 hulkfight::ai::TargetVelocityYCondition::vfunc_6 (242 B): equivalent/0x00125f90.cpp [wrapped: conflict: DAT_00494b44; DAT_00494b60; hulkfight::ai::TargetVelocityYCondition]
// sym: ?vfunc_6@TargetVelocityYCondition@ai@hulkfight@fn_00125f90@@UAE_NPAXPAUActor_125f90@4@0@Z
namespace fn_00125f90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::ai::TargetVelocityYCondition::vfunc_6 @ 0x00125f90
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00018960(float, float, float);
struct Velocity_125f90 { char pad[0x54]; float y; };
struct Entity { char pad[0x328]; Velocity_125f90* velocity; };
struct Controller_125f90 { Entity* FUN_00059a30(); };
struct Actor_125f90 { Controller_125f90* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct TargetVelocityYCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual bool vfunc_6(void*, Actor_125f90*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool TargetVelocityYCondition::vfunc_6(void*, Actor_125f90* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Entity* entity = actor->FUN_000592a0()->FUN_00059a30();
 if (!entity->velocity) return false;
 float y = entity->velocity->y;
 switch(comparison) {
 case 0: return y < threshold;
 case 1: return y <= threshold;
 case 2: return FUN_00018960(y,threshold,0.00001f);
 case 3: return !FUN_00018960(y,threshold,0.00001f);
 case 4: return y >= threshold;
 case 5: return y > threshold;
 default: return false;
 }
}
} }
} // namespace fn_00125f90


// 0x001260a0 hulkfight::ai::TargetDirectionCondition::vfunc_6 (437 B): equivalent/0x001260a0.cpp
// sym: ?vfunc_6@TargetDirectionCondition@ai@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::TargetDirectionCondition::vfunc_6 @ 0x001260a0
bool hulkfight::ai::TargetDirectionCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1260a0 * params = (fight::Params_1260a0 *)__p1; int b = (int)__p2;

    CFightParams_1260a0 *fp = dynamic_cast<CFightParams_1260a0 *>(params);
    if (fp == 0)
        return 0;
    Fighter_1260a0 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Target_1260a0 *target = fighter->target;
    if (target == 0)
        return 0;
    V3_1260a0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->anchor->FUN_00059a50(&pos);
    V3_1260a0 d;
    d.x = pos.x - target->pos.x;
    d.y = pos.y - target->pos.y;
    d.z = pos.z - target->pos.z;
    d.FUN_0022d110();
    V3_1260a0 e = target->dir;
    e.FUN_0022d110();
    float dot = e.z * d.z + e.y * d.y + e.x * d.x;
    switch (this->f_0c) {
    case 0:
        return dot < this->f_10;
    case 1:
        return dot <= this->f_10;
    case 2:
        return FUN_00018960(dot, this->f_10, 1e-5f);
    case 3:
        return !FUN_00018960(dot, this->f_10, 1e-5f);
    case 4:
        return dot >= this->f_10;
    case 5:
        return dot > this->f_10;
    }
    return 0;
}


// 0x00126270 hulkfight::ai::TargetDirectionXZCondition::vfunc_6 (441 B): equivalent/0x00126270.cpp
// sym: ?vfunc_6@TargetDirectionXZCondition@ai@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 17/18, incomplete)
// hulkfight::ai::TargetDirectionXZCondition::vfunc_6 @ 0x00126270
bool hulkfight::ai::TargetDirectionXZCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_126270 * params = (fight::Params_126270 *)__p1; int b = (int)__p2;

    CFightParams_126270 *fp = dynamic_cast<CFightParams_126270 *>(params);
    if (fp == 0)
        return 0;
    Fighter_126270 *fighter = params->FUN_000592a0()->FUN_00059a30();
    Target_126270 *target = fighter->target;
    if (target == 0)
        return 0;
    V3_126270 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    fighter->anchor->FUN_00059a50(&pos);
    V3_126270 d;
    d.x = pos.x - target->pos.x;
    d.y = 0.0f;
    d.z = pos.z - target->pos.z;
    d.FUN_0022d110();
    V3_126270 e = target->dir;
    e.y = 0.0f;
    e.FUN_0022d110();
    float dot = e.z * d.z + d.x * e.x + e.y * d.y;
    switch (this->f_0c) {
    case 0:
        return dot < this->f_10;
    case 1:
        return dot <= this->f_10;
    case 2:
        return FUN_00018960(dot, this->f_10, 1e-5f);
    case 3:
        return !FUN_00018960(dot, this->f_10, 1e-5f);
    case 4:
        return dot >= this->f_10;
    case 5:
        return dot > this->f_10;
    }
    return 0;
}


// 0x00126450 hulkfight::ai::TargetDirectionYCondition::vfunc_6 (341 B): equivalent/0x00126450.cpp
// sym: ?vfunc_6@TargetDirectionYCondition@ai@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 28/28)
// hulkfight::ai::TargetDirectionYCondition::vfunc_6 @ 0x00126450
bool hulkfight::ai::TargetDirectionYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; Owner_126450 * owner = (Owner_126450 *)__p1; int unused3 = (int)__p2;

    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return (bool)(0);
    Actor_126450 *actor = ((Chain_126450 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    Target_126450 *t = actor->target;
    if (!t)
        return (bool)(0);

    Vec3_126450 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    actor->locator->FUN_00059a50(&v);

    hulk_freg d = (v.y - t->pos.y) * t->scale;
    float s;
    if (d < 0.0f)
        s = -1.0f;
    else if (d > 0.0f)
        s = 1.0f;
    else
        s = 0.0f;
    int dir = (int)s;

    switch (this->f_0c) {
    case 0:
        return (bool)(dir < this->f_10);
    case 1:
        return (bool)(dir <= this->f_10);
    case 2:
        return (bool)(dir == this->f_10);
    case 3:
        return (bool)(dir != this->f_10);
    case 4:
        return (bool)(dir >= this->f_10);
    case 5:
        return (bool)(dir > this->f_10);
    }
    return (bool)(0);
}


// 0x001265c0 hulkfight::ai::TargetAngleYCondition::vfunc_6 (416 B): equivalent/0x001265c0.cpp
// sym: ?vfunc_6@TargetAngleYCondition@ai@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 26/28, incomplete)
// hulkfight::ai::TargetAngleYCondition::vfunc_6 @ 0x001265c0
bool hulkfight::ai::TargetAngleYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * obj = (void *)__p1; int c = (int)__p2;

    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return (bool)(0);
    Res_1265c0 *r = ((Resolver_1265c0 *)((owners::Object_592a0 *)(((Target_1265c0 *)obj)))->FUN_000592a0())->FUN_00059a30();
    Body_1265c0 *body = r->body;
    if (!body)
        return (bool)(0);
    Vec3_1265c0 from;
    from.x = 0.0f;
    from.y = 0.0f;
    from.z = 0.0f;
    r->loc->FUN_00059a50(&from);
    Vec3_1265c0 d;
    d.x = body->pos.x - from.x;
    d.y = body->pos.y - from.y;
    d.z = body->pos.z - from.z;
    FUN_0022d110(&d);
    float y = d.y;
    float s;
    if (y >= -1.0f && y <= 1.0f)
        s = y;
    else if (y > 1.0f)
        s = 1.0f;
    else
        s = -1.0f;
    double ang = FUN_000189c0(s);
    switch (this->f_0c) {
    case 0: return (bool)(ang < this->f_10);
    case 1: return (bool)(ang <= this->f_10);
    case 2: return (bool)(ang == this->f_10);
    case 3: return (bool)(ang != this->f_10);
    case 4: return (bool)(ang >= this->f_10);
    case 5: return (bool)(ang > this->f_10);
    }
    return (bool)(0);
}

namespace fn_f038364c {

// 0x00126780 FUN_00126780 (72 B): matches/0x00126780.cpp
// sym: ??0AcquireTargetAction_126780@fn_f038364c@@QAE@HPAVRefObj_126780@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
AcquireTargetAction_126780::AcquireTargetAction_126780(int target, RefObj_126780* obj) {
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


// 0x001267d0 FUN_001267d0 (50 B): matches/0x001267d0.cpp
// sym: ??1AcquireTargetAction_1267d0@fn_f038364c@@QAE@XZ
AcquireTargetAction_1267d0::~AcquireTargetAction_1267d0() {
    vptr = hulk_at_00410004;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1267d0 *)this)->FUN_002326a0();
}


// 0x00126810 FUN_00126810 (72 B): matches/0x00126810.cpp
// sym: ??0ClearProjectileDistanceAction_126810@fn_f038364c@@QAE@HPAVRefObj_126810@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ClearProjectileDistanceAction_126810::ClearProjectileDistanceAction_126810(int target, RefObj_126810* obj) {
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


// 0x00126860 FUN_00126860 (50 B): matches/0x00126860.cpp
// sym: ??1ClearProjectileDistanceAction_126860@fn_f038364c@@QAE@XZ
ClearProjectileDistanceAction_126860::~ClearProjectileDistanceAction_126860() {
    vptr = hulk_at_00410020;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_126860 *)this)->FUN_002326a0();
}


// 0x001268a0 FUN_001268a0 (72 B): matches/0x001268a0.cpp
// sym: ??0TargetClearAction_1268a0@fn_f038364c@@QAE@HPAVRefObj_1268a0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
TargetClearAction_1268a0::TargetClearAction_1268a0(int target, RefObj_1268a0* obj) {
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


// 0x001268f0 FUN_001268f0 (50 B): matches/0x001268f0.cpp
// sym: ??1TargetClearAction_1268f0@fn_f038364c@@QAE@XZ
TargetClearAction_1268f0::~TargetClearAction_1268f0() {
    vptr = hulk_at_0041003c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1268f0 *)this)->FUN_002326a0();
}


// 0x00126930 FUN_00126930 (46 B): matches/0x00126930.cpp
// sym: ??0ParamEnumConstList_126930@fn_f038364c@@QAE@HHHH@Z
ParamEnumConstList_126930::ParamEnumConstList_126930(int x, int y, int z, int w) : ParamValueEnum_126930(x) {
    a = y;
    b = z;
    c = w;
}

} // namespace fn_f038364c

// 0x00126960 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_7 (6 B): matches/0x00126960.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126970 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_6 (30 B): matches/0x00126970.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126970 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126970*)&DAT_003f335c));
}


// 0x00126990 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_8 (26 B): matches/0x00126990.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::**)(int))&this->f_18))(b);
}


// 0x001269b0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_2 (11 B): matches/0x001269b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001269e0 fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_6 (26 B): matches/0x001269e0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::**)(int))&this->f_10))(b);
}


// 0x00126a00 fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_2 (11 B): matches/0x00126a00.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::ai::TargetDirectionYCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126a30 fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::vfunc_6 (26 B): matches/0x00126a30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))(b);
}


// 0x00126a50 fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::vfunc_2 (11 B): matches/0x00126a50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126a80 fight::ParamBool<hulkfight::ai::TargetArcCondition>::vfunc_6 (26 B): matches/0x00126a80.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetArcCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetArcCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))(b);
}


// 0x00126aa0 fight::ParamBool<hulkfight::ai::TargetArcCondition>::vfunc_2 (11 B): matches/0x00126aa0.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetArcCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126ad0 fight::ParamVector<hulkfight::ai::TargetArcCondition>::vfunc_6 (26 B): matches/0x00126ad0.cpp
// sym: ?vfunc_6@?$ParamVector@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::TargetArcCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::ai::TargetArcCondition>*)a)->*(*(bool (fight::ParamVector<hulkfight::ai::TargetArcCondition>::**)(int))&this->f_10))(b);
}


// 0x00126af0 fight::ParamVector<hulkfight::ai::TargetArcCondition>::vfunc_2 (11 B): matches/0x00126af0.cpp
// sym: ?vfunc_2@?$ParamVector@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::ai::TargetArcCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126b30 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_7 (6 B): matches/0x00126b30.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126b40 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_6 (30 B): matches/0x00126b40.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126b40 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126b40*)&DAT_003f335c));
}


// 0x00126b60 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_8 (26 B): matches/0x00126b60.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::**)(int))&this->f_18))(b);
}


// 0x00126b80 fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_2 (11 B): matches/0x00126b80.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00126bc0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_7 (6 B): matches/0x00126bc0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126bd0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_6 (30 B): matches/0x00126bd0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126bd0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126bd0*)&DAT_003f335c));
}


// 0x00126bf0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_8 (26 B): matches/0x00126bf0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x00126c10 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_2 (11 B): matches/0x00126c10.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00126c40 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_6 (26 B): matches/0x00126c40.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x00126c60 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_2 (11 B): matches/0x00126c60.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126c90 fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_6 (26 B): matches/0x00126c90.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetDistanceCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x00126cb0 fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_2 (11 B): matches/0x00126cb0.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126cf0 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_7 (6 B): matches/0x00126cf0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126d00 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_6 (30 B): matches/0x00126d00.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126d00 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126d00*)&DAT_003f335c));
}


// 0x00126d20 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_8 (26 B): matches/0x00126d20.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::**)(int))&this->f_18))(b);
}


// 0x00126d40 fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_2 (11 B): matches/0x00126d40.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetAngleYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00126d70 fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_6 (26 B): matches/0x00126d70.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::**)(int))&this->f_10))(b);
}


// 0x00126d90 fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_2 (11 B): matches/0x00126d90.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetAngleYCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126dd0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_7 (6 B): matches/0x00126dd0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126de0 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_6 (30 B): matches/0x00126de0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126de0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126de0*)&DAT_003f335c));
}


// 0x00126e00 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_8 (26 B): matches/0x00126e00.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::**)(int))&this->f_18))(b);
}


// 0x00126e20 fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_2 (11 B): matches/0x00126e20.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDirectionCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00126e50 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_6 (26 B): matches/0x00126e50.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::**)(int))&this->f_10))(b);
}


// 0x00126e70 fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_2 (11 B): matches/0x00126e70.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDirectionCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126eb0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_7 (6 B): matches/0x00126eb0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00126ec0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_6 (30 B): matches/0x00126ec0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_126ec0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_126ec0*)&DAT_003f335c));
}


// 0x00126ee0 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_8 (26 B): matches/0x00126ee0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_18))(b);
}


// 0x00126f00 fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_2 (11 B): matches/0x00126f00.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetDistanceYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00126f30 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_6 (26 B): matches/0x00126f30.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))(b);
}


// 0x00126f50 fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_2 (11 B): matches/0x00126f50.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetDistanceYCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126f80 fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_6 (26 B): matches/0x00126f80.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::**)(int))&this->f_10))(b);
}


// 0x00126fa0 fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_2 (11 B): matches/0x00126fa0.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::TargetDistanceYCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00126fd0 fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::vfunc_6 (26 B): matches/0x00126fd0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::**)(int))&this->f_10))(b);
}


// 0x00126ff0 fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::vfunc_2 (11 B): matches/0x00126ff0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetOrientationCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127030 fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_7 (6 B): matches/0x00127030.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00127040 fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6 (30 B): matches/0x00127040.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_127040 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_127040*)&DAT_003f335c));
}


// 0x00127060 fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_8 (26 B): matches/0x00127060.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_18))(b);
}


// 0x00127080 fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2 (11 B): matches/0x00127080.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001270b0 fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6 (26 B): matches/0x001270b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x001270d0 fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2 (11 B): matches/0x001270d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127100 fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6 (26 B): matches/0x00127100.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::**)(int))&this->f_10))(b);
}


// 0x00127120 fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2 (11 B): matches/0x00127120.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00127150 fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_6 (26 B): matches/0x00127150.cpp
// sym: ?vfunc_6@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::ai::HasTargetCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::ai::HasTargetCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::ai::HasTargetCondition>::**)(int))&this->f_10))(b);
}


// 0x00127170 fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_2 (11 B): matches/0x00127170.cpp
// sym: ?vfunc_2@?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::ai::HasTargetCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001271b0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_7 (6 B): matches/0x001271b0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001271c0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_6 (30 B): matches/0x001271c0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1271c0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1271c0*)&DAT_003f335c));
}


// 0x001271e0 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_8 (26 B): matches/0x001271e0.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::**)(int))&this->f_18))(b);
}


// 0x00127200 fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_2 (11 B): matches/0x00127200.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VTargetDirectionYCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::ai::TargetVelocityYCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00127230 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_6 (26 B): matches/0x00127230.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::**)(int))&this->f_10))(b);
}


// 0x00127250 fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_2 (11 B): matches/0x00127250.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::ai::TargetVelocityYCondition>::vfunc_2() {
    return this->f_10 == 0;
}

