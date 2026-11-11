// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00198900..0x00199630 (kind game, layer game, confidence medium), dominant class hulkfight::motion::ProjectileGroundShockwave
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3bcd8a9 {
#define TREE_TU_END }
namespace fn_f3bcd8a9 {} using namespace fn_f3bcd8a9;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3bcd8a9 {
class RefObj_198900 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_198900 {
  public:
    Action_198900();
    virtual void Update();
    char pad[0x18];
};
class FireGroundShockwaveAction_198900 : public Action_198900 {
  public:
    int mTarget;
    RefObj_198900* mObj;
    FireGroundShockwaveAction_198900(int target, RefObj_198900* obj);
    virtual void Execute();
};
extern void* g_vftable_198950[];
class Ref_198950 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_198950 {
  public:
    void* vptr;
};
class FireGroundShockwaveAction_198950 : public Action_198950 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_198950* m20;
    ~FireGroundShockwaveAction_198950();
};
struct Vec3_198990 { float x,y,z; };
struct Transform_198990 { char data[64]; void FUN_0022b980(); };
struct Params { char pad0[44]; unsigned field2c; char pad30[4]; unsigned field34; char pad38[8]; char position[28]; unsigned field5c; };
struct RenderState_198990 { char pad[112]; unsigned char enabled; unsigned char other; unsigned char flag; };
struct Object { virtual void AddRef(); virtual void Release(); unsigned field4; void* owner; unsigned type; char pad10[100]; RenderState_198990* state; };
struct CollisionSphere_198990 { CollisionSphere_198990* FUN_002efe50(Vec3_198990*, unsigned); };
extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" Object* __cdecl FUN_002efca0(CollisionSphere_198990*, unsigned);
struct Controller_198990 { void FUN_001b42b0(Object*); };
extern Controller_198990* __stdcall FUN_001b6580();
struct Manager_198990 { unsigned FUN_00283a40(void*, Transform_198990*, float, float); };
extern Manager_198990* __cdecl FUN_0027f250();
struct FUN_001b6800 { FUN_001b6800(); virtual void slot0(); char base[20]; };
} // namespace fn_f3bcd8a9
namespace hulkfight { namespace motion {
struct ProjectileGroundShockwave : FUN_001b6800 {
 Params* params; unsigned field1c,field20; Object* object; unsigned field28,field2c; float field30; unsigned field34,field38; unsigned cleared[32]; unsigned fieldbc;
 virtual void slot0();
 ProjectileGroundShockwave(Params* p);
};
} }
namespace fn_f3bcd8a9 {
extern void* g_vftable_198ab0[];
class Ref_198ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Mgr_198ab0 {
    void Remove(void* p);
};
struct Reg_198ab0 {
    void Fn(void* p);
};
Mgr_198ab0* GetMgr();
Reg_198ab0* __stdcall GetReg();
class CProjectile_198ab0 {
  public:
    void* vptr;
    void Fin();
};
class ProjectileGroundShockwave_198ab0 : public CProjectile_198ab0 {
  public:
    char pad4[0x14];
    void* m18;
    char pad1c[8];
    Ref_198ab0* m24;
    char pad28[0xc];
    void* m34;
    char pad38[4];
    Ref_198ab0* m3c[32];
    ~ProjectileGroundShockwave_198ab0() throw();
};


// 0x00198900 FUN_00198900 (72 B): matches/0x00198900.cpp
// sym: ??0FireGroundShockwaveAction_198900@fn_f3bcd8a9@@QAE@HPAVRefObj_198900@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
FireGroundShockwaveAction_198900::FireGroundShockwaveAction_198900(int target, RefObj_198900* obj) {
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


// 0x00198950 FUN_00198950 (50 B): matches/0x00198950.cpp
// sym: ??1FireGroundShockwaveAction_198950@fn_f3bcd8a9@@QAE@XZ
FireGroundShockwaveAction_198950::~FireGroundShockwaveAction_198950() {
    vptr = g_vftable_198950;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_198950 *)this)->FUN_002326a0();
}

} // namespace fn_f3bcd8a9

// 0x00198990 FUN_00198990 (275 B): equivalent/0x00198990.cpp
// sym: ??0ProjectileGroundShockwave@motion@hulkfight@@QAE@PAUParams@fn_f3bcd8a9@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 19901 inputs, branch coverage 4/4)
// FUN_00198990 @ 0x00198990
namespace hulkfight { namespace motion {
ProjectileGroundShockwave::ProjectileGroundShockwave(Params* p) {
 params=0; field1c=0; field20=0; object=0; field28=0; field2c=0; field30=-1.0f; field34=0; field38=0; fieldbc=0;
 params=p; *(unsigned*)(base+8)=p->field2c;
 CollisionSphere_198990* mem=(CollisionSphere_198990*)FUN_0008d690(72);
 CollisionSphere_198990* created=0;
 if(mem) { unsigned value=params->field34; Vec3_198990 v; v.x=0; v.y=0; v.z=0; created=mem->FUN_002efe50(&v,value); }
 Object* obj=FUN_002efca0(created,0);
 obj->type=6; obj->owner=this; obj->AddRef();
 if(object) object->Release();
 object=obj;
 RenderState_198990* state=obj->state; state->enabled=1; state->flag=0;
 Object* arg1_ = object;
 FUN_001b6580()->FUN_001b42b0(arg1_);
 Transform_198990 transform; transform.FUN_0022b980();
 Manager_198990* manager=FUN_0027f250();
 field34=manager->FUN_00283a40(params->position,&transform,-1.0f,1.0f);
 field38=params->field5c;
 for(int i=0;i<32;++i) cleared[i]=0;
}
} }

namespace fn_f3bcd8a9 {

// 0x00198ab0 FUN_00198ab0 (124 B): matches/0x00198ab0.cpp
// sym: ??1ProjectileGroundShockwave_198ab0@fn_f3bcd8a9@@QAE@XZ
ProjectileGroundShockwave_198ab0::~ProjectileGroundShockwave_198ab0() throw() {
    vptr = g_vftable_198ab0;
    _ReadWriteBarrier();
    Ref_198ab0** p = m3c;
    int n = 32;
    do {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        p++;
    } while (--n);
    if (m34) {
        Mgr_198ab0* g = GetMgr();
        g->Remove(m34);
    }
#if defined(__clang__)
    // MSVC reads m24 before calling GetReg(); clang calls GetReg() first
    void* arg = m24;
    GetReg()->Fn(arg);
#else
    GetReg()->Fn(m24);
#endif
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Fin();
}

} // namespace fn_f3bcd8a9

// 0x00198b30 hulkfight::motion::ProjectileGroundShockwave::vfunc_4 (1320 B): equivalent/0x00198b30.cpp [wrapped: conflict: FUN_0027f250; hulkfight::motion::ProjectileGroundShockwave]
// sym: ?vfunc_4@ProjectileGroundShockwave@motion@hulkfight@fn_00198b30@@UAEXM@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00198b30 {
// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 31/32, incomplete)
// hulkfight::motion::ProjectileGroundShockwave::vfunc_4 @ 0x00198b30
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
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
#endif


struct V3_198b30 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_198b30 *other, float eps);
};

struct Mat_198b30 {
    float m[16];
    void FUN_0022b980();
};

struct Rng_198b30 {
    hulk_freg FUN_000787e0(float lo, float hi);
};

extern "C" Rng_198b30 *__cdecl FUN_000964d0();
extern "C" void __cdecl FUN_00224d70(float angle, V3_198b30 *v);
extern "C" hulk_freg __cdecl FUN_00224f10(V3_198b30 *v);
extern "C" void __cdecl FUN_00224db0(Mat_198b30 *m, V3_198b30 *from, V3_198b30 *to);
extern "C++" __declspec(nothrow) hulk_freg __cdecl FUN_0004af40(float lo, float hi, float v);

struct Raycast {
    bool FUN_00201f20(V3_198b30 *p, int flag, V3_198b30 *hitA, V3_198b30 *hitB, int *o3, int *o4);
};

struct Spawner_198b30 {
    void FUN_001f6cd0(int a, int b, V3_198b30 *hitA, V3_198b30 *hitB, V3_198b30 *dir, int c, int d, int e, int *handle, int z);
};

class Pending;
class ProjectileGroundShockwave;

struct Registry_198b30 {
    void FUN_001ebf50(int handle, void *owner);
};

struct World {
    char pad0[0x24];
    Raycast *ray;       // 0x24
    char pad28[0x34 - 0x28];
    Registry_198b30 *reg;      // 0x34
    Spawner_198b30 *spawn;     // 0x38
};

struct Decal {
    void FUN_0027ffc0(void *what, Mat_198b30 *m);
};
Decal *FUN_0027f250();

struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat_198b30 *m, float dt);
    char pad04[0x0c];
    Mat_198b30 mat;
};

struct Cfg_198b30 {
    char pad0[0x28];
    float f28;
    float f2c;
    char pad30[0x3c - 0x30];
    float f3c;
    char pad40[0x48 - 0x40];
    V3_198b30 vec48;
    int i54;
    int i58;
    float f5c;
    int cntA;       // 0x60
    float f64;
    float f68;
    int cntB;       // 0x6c
    int i70;
};

struct Frame_198b30 {
    float s0;       // S0
    float s4;       // S4
    V3_198b30 disp;        // S8
    int o4;         // S20
    union {         // S24
        int handle;
        float f64;
    };
    V3_198b30 g;           // S28
    int o3;         // S40
    int s44;        // S44
    float step;     // S48
    float c3c;      // S52
    float c68;      // S56
    V3_198b30 P;           // S60
    int a1;         // S72
    Raycast *ray;   // S76
    V3_198b30 hitA;        // S80
    V3_198b30 hitB;        // S92
    Mat_198b30 mat;        // S104
    Mat_198b30 mat2;       // S168
};

namespace hulkfight {
namespace motion {

class ProjectileGroundShockwave {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(float dt);
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x8];
    float life;     // 0xc
    char active;    // 0x10
    char pad11[7];
    Cfg_198b30 *cfg;       // 0x18
    char pad1c[8];
    Node *node;     // 0x24
    V3_198b30 vel;         // 0x28
    void *p34;      // 0x34
    float acc;      // 0x38
};

void ProjectileGroundShockwave::vfunc_4(float dt)
{
    if (active)
        return;
    union { float f; unsigned int u; } ab;
    ab.f = dt;
    ab.u &= 0x7fffffff;
    if (ab.f <= 1e-5f)
        return;

    Frame_198b30 f;
    V3_198b30 *pv = &vel;
    Cfg_198b30 *c0 = cfg;
    double k = (double)c0->f28 / (double)c0->f2c;
    f.s4 = life;
    f.disp.x = pv->x;
    f.disp.y = pv->y;
    f.disp.z = pv->z;
    memcpy(&f.mat, &node->mat, 0x40);
    World *mgr = DAT_004dd700;
    double sc = k * dt;
    f.disp.x = (float)(f.disp.x * sc);
    f.disp.y = (float)(f.disp.y * sc);
    f.disp.z = (float)(f.disp.z * sc);
    f.mat.m[12] = f.mat.m[12] + f.disp.x;
    f.mat.m[13] = f.mat.m[13] + f.disp.y;
    f.mat.m[14] = f.mat.m[14] + f.disp.z;
    f.P.x = f.mat.m[12];
    f.P.y = f.mat.m[13];
    f.P.z = f.mat.m[14];
    f.c3c = c0->f3c;
    f.P.y = f.P.y + f.c3c;
    f.ray = mgr->ray;
    f.o3 = 0;
    f.o4 = 0;
    bool hit = f.ray->FUN_00201f20(&f.P, 1, &f.hitA, &f.hitB, &f.o3, &f.o4);

    float X;
    if (hit) {
        f.s0 = f.hitA.y - f.mat.m[13];
        ab.f = f.s0;
        ab.u &= 0x7fffffff;
        f.s0 = ab.f;
        if (!(f.s0 > f.c3c))
            X = f.s4;
        else
            X = 0.0f;
    } else {
        X = 0.0f;
    }
    double nl = (double)X - (double)dt;
    life = (float)nl;
    if (nl < 0.0)
        return;

    node->v6(&f.mat, dt);
    f.s4 = (float)sqrt(f.disp.z * f.disp.z + f.disp.y * f.disp.y + f.disp.x * f.disp.x);
    if (p34 != 0) {
        Decal *dc = FUN_0027f250();
        f.mat2.FUN_0022b980();
        f.g = cfg->vec48;
        f.g.FUN_0022d110();
        if (!vel.FUN_0022d2b0(&f.g, 1e-5f))
            FUN_00224db0(&f.mat2, &f.g, &vel);
        f.mat2.m[12] = f.mat.m[12];
        f.mat2.m[13] = f.mat.m[13];
        f.mat2.m[14] = f.mat.m[14];
        dc->FUN_0027ffc0(p34, &f.mat2);
    }

    Cfg_198b30 *c1 = cfg;
    f.s0 = c1->f5c;
    if (!(f.s0 > 0.0f))
        return;
    double acc2 = (double)f.s4 + (double)acc;
    acc = (float)acc2;
    if (!(acc2 > (double)f.s0))
        return;
    acc = (float)(acc2 - (double)f.s0);
    if (f.o3 != 0) {
        int cnt = c1->i54;
        if (cnt > 0) {
            Rng_198b30 *rng = FUN_000964d0();
            f.s4 = rng->FUN_000787e0(0.0f, 6.2831855f);
            f.g = (*(V3_198b30*)&DAT_004c1368);
            FUN_00224d70(f.s4, &f.g);
            int c58 = cfg->i58;
            f.s4 = *(float *)&c58;
            f.handle = 0;
            mgr->spawn->FUN_001f6cd0(f.o3, f.o4, &f.hitA, &f.hitB, &f.g, cnt - 1, c58, c58, &f.handle, 0);
            mgr->reg->FUN_001ebf50(f.handle, (void *)this);
        }
    }

    Cfg_198b30 *c2 = cfg;
    int A = c2->cntA;
    int B = c2->cntB;
    if (A <= 0)
        return;
    if (B <= 0)
        return;
    f.c68 = c2->f68;
    float h = f.c68 * 0.5f;
    f.a1 = A - 1;
    f.f64 = c2->f64;
    f.s44 = c2->i70;
    float phi = FUN_00224f10(&vel);
    f.s4 = phi - h;
    f.s0 = phi + h;
    f.step = (float)((double)f.c68 / (double)B);
    Rng_198b30 *rng2 = FUN_000964d0();
    float lo = f.s4;
    float hi = f.s0;
    f.s0 = rng2->FUN_000787e0(lo, hi);
    int n = B;
    int ebx = f.s44;
    do {
        float want = f.s0 + f.step;
        f.s0 = FUN_0004af40(f.s4, hi, want);
        f.g = (*(V3_198b30*)&DAT_004c1368);
        FUN_00224d70(f.s0, &f.g);
        hulk_freg gx = f.g.x * f.f64;
        hulk_freg gy = f.g.y * f.f64;
        f.disp.z = f.g.z * f.f64;       // the z product goes through disp.z (rounded) and is read back
        f.disp.x = f.mat.m[12] + gx;
        f.disp.z = f.mat.m[14] + *(volatile float *)&f.disp.z;
        hulk_freg ty = f.mat.m[13] + gy;   // (m13 + gy) + c3c, in that order
        f.disp.y = ty + f.c3c;
        if (f.ray->FUN_00201f20(&f.disp, 1, &f.hitA, &f.hitB, &f.o3, &f.o4)) {
            f.s44 = 0;
            mgr->spawn->FUN_001f6cd0(f.o3, f.o4, &f.hitA, &f.hitB, &f.g, f.a1, ebx, ebx, &f.s44, 0);
        }
        n--;
    } while (n != 0);
}

}
}
} // namespace fn_00198b30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00199060 hulkfight::motion::ProjectileGroundShockwave::vfunc_6 (1476 B): equivalent/0x00199060.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?F@ProjectileGroundShockwave@fn_00199060@@QAEDPAVThing_199060@2@PAVOther_199060@2@PAUV3_199060@2@HH@Z
namespace fn_00199060 {
// STATUS: equivalent (tools/equiv.py level 3: 3141 inputs, branch coverage 76/76)
// hulkfight::motion::ProjectileGroundShockwave::vfunc_6 @ 0x00199060
// hulkfight::motion::ProjectileGroundShockwave::vfunc_6 @ 0x00199060
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
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

struct V3_199060 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Name_199060 {
    unsigned int lo, hi;
};

struct Mat4_199060 {
    float m[16];
    void FUN_0022b980();
};

struct HitInfo_199060 {
    char pad0[8];
    V3_199060 pos;
    char pad14[0x28 - 0x14];
    V3_199060 ref;
    char pad34[0x64 - 0x34];
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x90 - 0x7c];
    char b90;
    char pad91[3];
    void FUN_00059820();
    void FUN_00059300();
};

class Ref_199060 {
public:
    virtual void v0();
    virtual void v1();
};

struct Req_199060 {
    void FUN_00083320(V3_199060 *a, int b, int c, int d, V3_199060 *e, int f);
};
struct Hub4c_199060 {
};

struct Fx_199060 {
    int FUN_00283a40(Name_199060 *id, Mat4_199060 *m, float a, float b);
};
Fx_199060 *FUN_0027f250();

struct Holder_199060 {
    float FUN_001dddf0();
};

struct Obj18_199060 {
    char pad0[0x38];
    float f38;
    char pad3c[0x74 - 0x3c];
    int f74;
    float f78;
    float f7c;
    V3_199060 v80;
    V3_199060 v8c;
    int f98;
    char pad9c[0xa8 - 0x9c];
    Name_199060 ida8;
};

struct Pad24 {
    char pad0[0x40];
    V3_199060 v40;
};

struct Info11c {
    char pad0[0x1b0];
    int f1b0;
};

class Ent_199060 {
public:
    char pad0[0x108];
    int f108;
    char pad10c[0x148 - 0x10c];
    void *f148;
    char pad14c[0x14d - 0x14c];
    char b14d;
    char pad14e[0x198 - 0x14e];
    int f198;
    float f19c;
    struct Sub6c *FUN_001d72e0();
    void FUN_001d82d0();
    char FUN_001d6ec0(int dmg, void *a, int b);
    void FUN_0027d4f0(int a);
    void FUN_001d86d0(V3_199060 *v, V3_199060 *hit);
};
struct Sub6c {
    char pad0[0x6c];
    void *f6c;
};

struct Own_199060 {
    char pad0[0x11c];
    Info11c *p11c;
    char pad120[0x12c - 0x120];
    void *f12c;
};

struct Pool44 {
};
struct World {
    char pad0[0xc];
    Holder_199060 *pc;
    char pad10[0x44 - 0x10];
    Pool44 *p44;
    char pad48[4];
    Hub4c_199060 *p4c;
};

struct IdHolder_199060 {
    char pad0[8];
    unsigned int lo;
    unsigned int hi;
};

class Thing_199060 {
public:
    char pad0[8];
    void *owner;
    int type;
    char pad10[0x74 - 0x10];
    IdHolder_199060 *p74;
};

struct Carried {
    char pad0[0x12c];
    Own_199060 *f12c;
};

struct OwnerObj_199060 {
    char pad0[0x10];
    int f10;
    struct Obj8_199060 *FUN_00081420x();
};
struct Obj8_199060 {
    void FUN_00081420(HitInfo_199060 *h);
};

class Other_199060 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x38 - 4];
    int f38;
    Ent_199060 *f3c;
};

extern "C" int FUN_00266da0(int mode);
void FUN_00224d70(float angle, V3_199060 *v);
hulk_freg FUN_00224f10(V3_199060 *v);
extern "C" char FUN_00195560(V3_199060 *pn, void *own, V3_199060 *b, int f1c, int f98, int z0, int a4, int Tbits, int f78, int f20, int f74,
                  int z1, float one, int z2);
extern "C" int __cdecl FUN_0034483c();

class ProjectileGroundShockwave {
public:
    char pad0[0xc];
    float f0c;
    char pad10[8];
    Obj18_199060 *p18;
    int f1c;
    float f20;
    Pad24 *p24;
    V3_199060 v28;
    char pad34[0x3c - 0x34];
    Ref_199060 *objs[32];
    int idx;
    char F(Thing_199060 *a1, Other_199060 *a2, V3_199060 *a3, int a4, int a5);
};

static void PlayEffect(ProjectileGroundShockwave *self, Mat4_199060 &M, V3_199060 *a3)
{
    if (self->p18->ida8.lo | self->p18->ida8.hi) {
        M.FUN_0022b980();
        float *t = &M.m[12];
        V3_199060 hit = *a3;
        t[0] = hit.x;
        t[1] = hit.y;
        t[2] = hit.z;
        Fx_199060 *fx = FUN_0027f250();
        fx->FUN_00283a40(&self->p18->ida8, &M, -1.0f, 1.0f);
    }
}

char ProjectileGroundShockwave::F(Thing_199060 *a1, Other_199060 *a2, V3_199060 *a3, int a4, int a5)
{
    struct Frame {
        float T;
        float f14;
        V3_199060 Q;
        int old;
        V3_199060 P;
        Mat4_199060 M;
        HitInfo_199060 X;
    } fr;
    int old = FUN_00266da0(0xd);
    fr.old = old;
    do {
        if (f0c < 0.0f)
            break;
        V3_199060 W0 = p24->v40;
        if (a3->y < W0.y)
            break;
        if (a3->y - W0.y > p18->f38)
            break;
        void *ebx = a1;
        Ent_199060 *edi = 0;
        if (a1->p74->lo == DAT_004e2198 && a1->p74->hi == (*(unsigned int*)&DAT_004e219c)) {
            if (a2->v6() == 4) {
                if (a2->f38 != 5)
                    break;
                edi = a2->f3c;
                ebx = edi->FUN_001d72e0();
            }
        }
        bool found = false;
        for (int i = 0; i < 32; i++) {
            if (objs[i] == (Ref_199060 *)ebx) {
                found = true;
                break;
            }
        }
        if (found)
            break;
        Ref_199060 **slot = &objs[idx];
        if (ebx)
            ((Ref_199060 *)ebx)->v0();
        if (*slot)
            (*slot)->v1();
        *slot = (Ref_199060 *)ebx;
        idx = (idx + 1) % 32;
        Own_199060 *own = ((Own_199060 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->p44))->FUN_00059c10((void *)(hulk_uintptr)(int)f1c));
        if (own && own->f12c == ebx)
            break;
        Obj18_199060 *o18 = p18;
        fr.T = o18->f78;
        if (o18->f7c > 0.0f)
            fr.T = (o18->f7c - fr.T) * f20 + fr.T;
        fr.P = o18->v80;
        fr.Q = o18->v8c;
        if (fr.Q.z * fr.Q.z + fr.Q.y * fr.Q.y + fr.Q.x * fr.Q.x > 0.0f) {
            fr.f14 = f20;
            float dx = fr.Q.x - fr.P.x;
            float dy = fr.Q.y - fr.P.y;
            float dz = fr.Q.z - fr.P.z;
            fr.P.x = dx * f20 + fr.P.x;
            fr.P.y = dy * f20 + fr.P.y;
            fr.P.z = dz * f20 + fr.P.z;
        }
        bool carried = false;
        void *carriedObj = 0;
        if (edi == 0) {
            int ty = ((Thing_199060 *)ebx)->type;
            bool toEdi = false;
            if (ty == 5) {
                edi = (Ent_199060 *)((Thing_199060 *)ebx)->owner;
                if (edi)
                    toEdi = true;
            }
            if (!toEdi) {
                if (ty == 1) {
                    carriedObj = ((Thing_199060 *)ebx)->owner;
                    if (!carriedObj)
                        break;
                    carried = true;
                } else if (ty == 7) {
                    OwnerObj_199060 *oo = (OwnerObj_199060 *)((Thing_199060 *)ebx)->owner;
                    if (oo->f10 == 5)
                        break;
                    fr.X.FUN_00059820();
                    fr.X.pos.x = a3->x;
                    fr.X.pos.y = a3->y;
                    fr.X.pos.z = a3->z;
                    fr.X.ref.x = fr.P.x;
                    fr.X.ref.y = fr.P.y;
                    fr.X.ref.z = fr.P.z;
                    fr.X.f78 = 1.0f;
                    fr.X.f64 = 30.0f;
                    fr.X.b90 = 1;
                    ((Obj8_199060 *)oo)->FUN_00081420(&fr.X);
                    fr.X.FUN_00059300();
                    break;
                } else {
                    break;
                }
            }
        }
        if (!carried) {
            void *f148 = edi->f148;
            if (f148 != 0) {
                carriedObj = f148;
                carried = true;
            }
        }
        if (carried) {
            fr.Q = fr.P;
            fr.T = fr.Q.FUN_0022d110();
            float ang = FUN_00224f10(&v28);
            FUN_00224d70(ang, &fr.Q);
            Obj18_199060 *o = p18;
            char r = FUN_00195560(&fr.Q, ((Carried *)carriedObj)->f12c, a3, f1c, o->f98, 0, a4, *(int *)&fr.T,
                                  *(int *)&o->f78, *(int *)&f20, o->f74, 0, 1.0f, 0);
            if (r)
                PlayEffect(this, fr.M, a3);
            break;
        }
        if (own) {
            bool same = false;
            for (int b = 0; b < 8; b++) {
                if (((Ent_199060 *)((owners::C_35ef0 *)own)->FUN_00035ef0((hulk_intptr)b)) == edi) {
                    same = true;
                    break;
                }
            }
            if (same)
                break;
        }
        edi->FUN_001d82d0();
        void *ownerF12c = 0;
        if (own) {
            int k = own->p11c->f1b0;
            if (edi->f198 == k)
                fr.T = fr.T * edi->f19c;
            if (k == 2)
                fr.T = DAT_004dd700->pc->FUN_001dddf0() * fr.T;
            ownerF12c = own->f12c;
        }
        char hit = edi->FUN_001d6ec0((int)fr.T, ownerF12c, 0);
        if (hit) {
            if (edi->f108 > 0)
                edi->FUN_0027d4f0(1);
        }
        PlayEffect(this, fr.M, a3);
        if (edi->b14d) {
            Sub6c *ev = edi->FUN_001d72e0();
            if (ev->f6c == 0) {
                Req_199060 *r = ((Req_199060 *)((owners::Obj_7ad00 *)(DAT_004dd700->p4c))->FUN_0007ad00((hulk_intptr)((char *)edi + 8)));
                if (!r)
                    break;
                V3_199060 V = p18->v80;
                r->FUN_00083320(a3, a4, a5, 1, &V, 0);
                break;
            }
        }
        float ang = FUN_00224f10(&v28);
        FUN_00224d70(ang, &fr.P);
        edi->FUN_001d86d0(&fr.P, a3);
    } while (0);
    FUN_00266da0(old);
    return 1;
}
} // namespace fn_00199060
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

