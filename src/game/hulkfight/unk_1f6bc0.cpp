// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f6bc0..0x001f76c0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f90a56c8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f90a56c8 {} using namespace fn_f90a56c8;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f90a56c8 {
struct Vec3_1f6bc0 {
    float x, y, z;
};
struct ThisCall_00283900 {
    void FUN_00283900(int, int);
};
struct Obj_1f6c50;
struct Sub_1f6c50 {
};
struct Mgr_1f6c50 {
    char pad[0x54];
    Sub_1f6c50* s;
};
extern Mgr_1f6c50* hulk_at_004dd700;
struct Obj_1f6c50 {
    char pad[0x4c];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad2[1];
    int x;
    int y;
    void Init_002833a0(void* v);
};
struct Obj_1f6c90 {
    void DoThing_00283340();
    void Finish_002833f0();
};
Obj_1f6c90* __cdecl GetObj_0027f250();
extern "C" int __cdecl FUN_0027f250();
class C_1f6cb0 {
  public:
    void FUN_00283340();
};
struct Vec3_1f6e60 { float x,y,z; };
struct Transform_1f6e60 { char data[64]; void FUN_0022ba00();  void FUN_0022bec0(const Vec3_1f6e60*,const Vec3_1f6e60*); };
struct Handle_1f6e60 { char data[8]; void FUN_0027b0e0(void*); void FUN_0027af50(); };
struct Service_1f6e60 { int FUN_00283a40(Handle_1f6e60*,Transform_1f6e60*,float,float); };
struct Object { char pad[0x24]; Vec3_1f6e60 position; Vec3_1f6e60 direction; Vec3_1f6e60 rotation; Service_1f6e60* FUN_0027f250(); int target(void*); };
struct Id64_1f6f30 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Emitter_1f6f30 {
    void *FUN_002842e0(Id64_1f6f30 *id, int a, int b, void *c, void *d, float *scale, int e, int f);
};
class Spawner_1f6f30 {
public:
    char pad00[0x1c];
    int f1c;
    int f20;
    char f24[0x18];         // 0x24
    char f3c[0xc];          // 0x3c
    int f48;                // 0x48
    char pad4c[0xc];
    float scaleA;           // 0x58
    float scaleB;           // 0x5c
    Emitter_1f6f30 *FUN_0027f250();
    void *FUN_001f6f30(const char *name, float scale, int arg);
};
class Item {
  public:
    float Apply_0027ffe0(float*);
};
class Obj {
  public:
    char _m_pad_0[0x24];
    float val;
    Item* GetItem_0027f250();
    hulk_freg Run();
    void FUN_001c3830(void*, void*);
};
extern "C" Obj* __cdecl FUN_001c3d90();
struct V3_1f7200 {
    float x, y, z;
};
struct T_1f7200 {
    char d[8];
    T_1f7200(int a);
    ~T_1f7200();
};
struct A_1f7200 {
    char d[0x40];
    A_1f7200();
};
struct S_1f7200 {
    void* Do_00283a40(T_1f7200* t, A_1f7200* a, float lo, float hi);
};
S_1f7200* GetS_0027f250();
struct Vec3_1f7280 {
    float x, y, z;
};
class Obj_1f7280 {
  public:
    void Act_0027ffd0(int, Vec3_1f7280*);
};
Obj_1f7280* Get_0027f250();
class Host_1f7280 {
  public:
    unsigned char target(int a, Vec3_1f7280 b);
};


// 0x001f6bc0 FUN_001f6bc0 (47 B): matches/0x001f6bc0.cpp
// sym: ?f@fn_f90a56c8@@YIXPAUVec3_1f6bc0@1@PAXPBU21@M2@Z
void __fastcall f(Vec3_1f6bc0* self, void* edx, const Vec3_1f6bc0* a, float s, const Vec3_1f6bc0* b) {
    self->x = s * b->x + a->x;
    self->y = s * b->y + a->y;
    self->z = s * b->z + a->z;
}


// 0x001f6c30 FUN_001f6c30 (16 B): matches/0x001f6c30.cpp
// sym: ?FUN_001f6c30@fn_f90a56c8@@YIPAXPAX@Z
void* __fastcall FUN_001f6c30(void* self) {
    ((ThisCall_00283900*)(self))->FUN_00283900(5, 0x10);
    return self;
}


// 0x001f6c50 FUN_001f6c50 (52 B): matches/0x001f6c50.cpp
// sym: ?FUN_001f6c50@fn_f90a56c8@@YIXPAUObj_1f6c50@1@PAXH@Z
void __fastcall FUN_001f6c50(Obj_1f6c50* self, void*, int unused) {
    Sub_1f6c50* a = hulk_at_004dd700->s;
    Sub_1f6c50* b = ((Sub_1f6c50 *)((owners::Target_862a0 *)a)->FUN_000862a0());
    void* v = ((void *)((owners::Target_203d70 *)b)->FUN_00203d70());
    self->Init_002833a0(v);
    self->a = 0;
    self->x = 0;
    self->b = 0;
    self->y = 0;
    self->c = 0;
}


// 0x001f6c90 FUN_001f6c90 (24 B): matches/0x001f6c90.cpp
// sym: _FUN_001f6c90
// Same code shape as 0x001bc510 (propagated; names are from that function)
extern "C" void FUN_001f6c90(void* /*this, unused: callers pass it (unb4)*/) {
    Obj_1f6c90* p = GetObj_0027f250();
    p->DoThing_00283340();
    p = GetObj_0027f250();
    p->Finish_002833f0();
}


// 0x001f6cb0 FUN_001f6cb0 (17 B): matches/0x001f6cb0.cpp
// sym: ?FUN_001f6cb0@fn_f90a56c8@@YAXPAX@Z
void __cdecl FUN_001f6cb0(void* /*this, unused: callers pass it (unb4)*/) {
    hulk_intptr value = FUN_0027f250();
    if (value != 0)
        ((C_1f6cb0*)value)->FUN_00283340();
}


// 0x001f6e60 FUN_001f6e60 (200 B): equivalent/0x001f6e60.cpp
// sym: ?target@Object@fn_f90a56c8@@QAEHPAX@Z @67f733198930 @wba0377e7647d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f6e60 @ 0x001f6e60
int Object::target(void* arg) {
 Service_1f6e60* service=FUN_0027f250();
 int result=0;
 if(service) {
 Vec3_1f6e60 point;
 point.x=direction.x*0.01f+position.x;
 point.y=direction.y*0.01f+position.y;
 point.z=direction.z*0.01f+position.z;
 Transform_1f6e60 transform;
 transform.FUN_0022ba00();
 ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(const Vec3_1f6e60 *)(&point));
 transform.FUN_0022bec0(&direction,&rotation);
 Handle_1f6e60 handle;
 handle.FUN_0027b0e0(arg);
 result=service->FUN_00283a40(&handle,&transform,-1.0f,1.0f);
 handle.FUN_0027af50();
 }
 return result;
}


// 0x001f6f30 FUN_001f6f30 (131 B): equivalent/0x001f6f30.cpp
// sym: ?FUN_001f6f30@Spawner_1f6f30@fn_f90a56c8@@QAEPAXPBDMH@Z @1b556dc0fbee @wf94c82649b7f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f6f30 @ 0x001f6f30
void *Spawner_1f6f30::FUN_001f6f30(const char *name, float scale, int arg)
{
    void *result = 0;
    Emitter_1f6f30 *emitter = FUN_0027f250();

    scaleA = scale * scaleA;
    scaleB = scale * scaleB;

    if (emitter != 0) {
        Id64_1f6f30 id;
        id.FUN_0027b0e0(name);
        result = emitter->FUN_002842e0(&id, f1c, f20, f24, f3c, &scaleA, arg, f48);
        id.FUN_0027af50();
    }
    return result;
}


// 0x001f6fc0 FUN_001f6fc0 (42 B): matches/0x001f6fc0.cpp
// sym: ?Run@Obj@fn_f90a56c8@@QAEMXZ
hulk_freg Obj::Run() {
    volatile float f = 10000.0f;
    Item* p = GetItem_0027f250();
    if (p)
        return p->Apply_0027ffe0(&val);
    return f;
}

} // namespace fn_f90a56c8

// 0x001f7110 FUN_001f7110 (10 B): matches/0x001f7110.cpp
// sym: ?FUN_001f7110@Obj_1f7110@owners@@QAEDH@Z
char owners::Obj_1f7110::FUN_001f7110(int arg) {
    char old = *(char*)((char*)this + 0x4e);
    *(char*)((char*)this + 0x4e) = 0;
    (void)arg;
    return old;
}

namespace fn_f90a56c8 {

// 0x001f7120 FUN_001f7120 (23 B): matches/0x001f7120.cpp
// sym: _FUN_001f7120
// FUN_001f7120 @ 0x001f7120
// FUN_001f7120 @ 0x001f7120
  // 0-argument singleton getter
extern "C" void __cdecl FUN_001f7120(void* first, void* second) {
    FUN_001c3d90()->FUN_001c3830(first, second);
}

// 0x001f7140 thunk_FUN_001b8750 (5 B): not yet verified
} // namespace fn_f90a56c8

// 0x001f7150 FUN_001f7150 (166 B): equivalent/0x001f7150.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?FUN_001f7150@fn_001f7150@@YGPAXHUVec3_1f7150@1@MMM@Z @f2195dd75be9 @w0ca3ee9a650f
namespace fn_001f7150 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f7150 @ 0x001f7150
// equiv-map: ??0Name@@QAE@H@Z = 0x0027b0e0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50

struct Vec3_1f7150 {
    float x, y, z;
};

struct Name {
    int lo, hi;
    Name(int key);
    ~Name();
};

struct Mat_1f7150 {
    float m[16];
    void FUN_0022b980();
};

struct Placer_1f7150 {
    void *FUN_00283a40(const Name &name, const Mat_1f7150 &m, float lo, float hi);
};

Placer_1f7150 *FUN_0027f250();

void * __stdcall FUN_001f7150(int key, Vec3_1f7150 pos, float rx, float ry, float rz)
{
    Mat_1f7150 m;
    m.FUN_0022b980();
    ((owners::Matrix_22bc20 *)&m)->FUN_0022bc20(rx * 0.01745329238474369f, ry * 0.01745329238474369f, rz * 0.01745329238474369f);
    ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)(Vec3_1f7150 *)(&pos));
    Placer_1f7150 *placer = FUN_0027f250();
    if (placer == 0)
        return 0;
    Name name(key);
    return placer->FUN_00283a40(name, m, -1.0f, 1.0f);
}
} // namespace fn_001f7150

namespace fn_f90a56c8 {

// 0x001f7200 FUN_001f7200 (113 B): matches/0x001f7200.cpp
// sym: ?F@fn_f90a56c8@@YGPAXHUV3_1f7200@1@@Z
void* __stdcall F(int a1, V3_1f7200 v) {
    void* r = 0;
    A_1f7200 a;
    ((owners::Target_22be40 *)&a)->FUN_0022be40((const int *)(V3_1f7200 *)(&v));
    S_1f7200* s = GetS_0027f250();
    if (s) {
        T_1f7200 t(a1);
        r = s->Do_00283a40(&t, &a, -1.0f, 1.0f);
    }
    return r;
}


// 0x001f7280 FUN_001f7280 (43 B): matches/0x001f7280.cpp
// sym: ?target@Host_1f7280@fn_f90a56c8@@QAEEHUVec3_1f7280@2@@Z
// b..d: a vector passed by value (the caller passes a math::Vector).
unsigned char Host_1f7280::target(int a, Vec3_1f7280 b) {
    if (a < 0)
        return 0;
    Obj_1f7280* p = Get_0027f250();
    if (p)
        p->Act_0027ffd0(a, &b);
    return 1;
}

} // namespace fn_f90a56c8

// 0x001f7320 FUN_001f7320 (833 B): equivalent/0x001f7320.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?FUN_001f7320@Spawner_1f7320@fn_001f7320@@QAEXPAUScene_1f7320@2@M@Z @b341e5b0b6f8 @w07e7bc7582f4
namespace fn_001f7320 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 22/22)
// FUN_001f7320 @ 0x001f7320

struct Vec3_1f7320 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022b9c0();
    void FUN_0022baf0(Vec3_1f7320 *axis, float angle);
};

class Rng_1f7320 {
public:
    hulk_freg FUN_000787e0(float lo, float hi);
};

class Actor_1f7320 {
public:
    void FUN_000352b0(Vec3_1f7320 *out);
};

struct Controlled {
    char pad0[0x124];
    Actor_1f7320 *actor;
};

class Caster_1f7320 {
public:
    char FUN_00201f20(Vec3_1f7320 *from, int mask, Vec3_1f7320 *hit, Vec3_1f7320 *normal, void **hitObj, int *hitPart);
};

class Source_1f7320 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual Matrix *vf14();
};

class Camera {
public:
    Source_1f7320 *FUN_00099180();
};

struct Scene_1f7320 {
    char pad0[8];
    Camera *camera;
    char pad1[0x20 - 0x0c];
    Controlled *controlled;
    Caster_1f7320 *caster;
};

class Renderer_1f7320 {
public:
    void FUN_0027ffc0(int id, Matrix *m);
    void FUN_00283a10(float dt);
};

extern "C" Rng_1f7320 *FUN_000964d0();
Renderer_1f7320 *FUN_0027f250();

class Spawner_1f7320 {
public:
    void FUN_001f7320(Scene_1f7320 *scene, float dt);
    void FUN_001f6cd0(void *hitObj, int hitPart, Vec3_1f7320 *hit, Vec3_1f7320 *normal, Vec3_1f7320 *axis, int kind,
                      float a, float b, int c, int d);

    char pad0[0x4c];
    char sparksA;
    char sparksC;
    char sparksB;
    char pad1;
    int slotA;
    int slotC;
};

void Spawner_1f7320::FUN_001f7320(Scene_1f7320 *scene, float dt)
{
    Vec3_1f7320 hit1;
    Vec3_1f7320 normal1;
    Vec3_1f7320 hit2;
    if (sparksA) {
        DAT_004e58dc = DAT_004e58dc - dt;
        if (DAT_004e58dc < 0.0f) {
            Rng_1f7320 *rng = FUN_000964d0();
            DAT_004e58dc = rng->FUN_000787e0(0.0f, 0.1f);
            void *hitObj = 0;
            int hitPart = 0;
            Vec3_1f7320 p;
            scene->controlled->actor->FUN_000352b0(&p);
            p.y = p.y + 5.0f;
            p.x = ((owners::RandomGen_143100 *)rng)->FUN_00143100() * 10.0f + p.x;
            p.z = ((owners::RandomGen_143100 *)rng)->FUN_00143100() * 10.0f + p.z;
            if (scene->caster->FUN_00201f20(&p, 0, &hit1, &normal1, &hitObj, &hitPart)) {
                if (hitObj != 0) {
                    Vec3_1f7320 axis;
                    axis.x = 1.0f;
                    axis.y = 0.0f;
                    axis.z = 0.0f;
                    FUN_001f6cd0(hitObj, hitPart, &hit1, &normal1, &axis, 6, 1.0f, 1.0f, 0, 0);
                }
            }
        }
        Matrix m;
        m.FUN_0022b980();
        if (scene->camera->FUN_00099180()) {
            Matrix *src = scene->camera->FUN_00099180()->vf14();
            m = *src;
            m.FUN_0022b9c0();
        }
        Renderer_1f7320 *r = FUN_0027f250();
        r->FUN_0027ffc0(slotA, &m);
    }
    if (sparksB) {
        DAT_004e58d8 = DAT_004e58d8 - dt;
        if (DAT_004e58d8 < 0.0f) {
            Rng_1f7320 *rng = FUN_000964d0();
            DAT_004e58d8 = rng->FUN_000787e0(0.0f, 0.2f);
            void *hitObj = 0;
            int hitPart = 0;
            Vec3_1f7320 p;
            scene->controlled->actor->FUN_000352b0(&p);
            Matrix m;
            m.FUN_0022b980();
            Vec3_1f7320 axis;
            axis.x = 0.0f;
            axis.y = 1.0f;
            axis.z = 0.0f;
            m.FUN_0022baf0(&axis, rng->FUN_000787e0(0.0f, 6.2831855f));
            Vec3_1f7320 v;
            v.x = rng->FUN_000787e0(10.0f, 50.0f);
            v.y = 5.0f;
            v.z = 0.0f;
            ((owners::Mat_22c2b0 *)&m)->FUN_0022c2b0((float *)(Vec3_1f7320 *)(&v), (float *)(Vec3_1f7320 *)(&v));
            p.x = p.x + v.x;
            p.y = p.y + v.y;
            p.z = p.z + v.z;
            if (scene->caster->FUN_00201f20(&p, 0, &hit2, &hit1, &hitObj, &hitPart)) {
                if (hitObj != 0) {
                    Vec3_1f7320 axis2;
                    axis2.x = 1.0f;
                    axis2.y = 0.0f;
                    axis2.z = 0.0f;
                    FUN_001f6cd0(hitObj, hitPart, &hit2, &hit1, &axis2, 7, 1.0f, 1.0f, 0, 0);
                }
            }
        }
    }
    if (sparksC) {
        Matrix m;
        m.FUN_0022b980();
        if (scene->camera->FUN_00099180()) {
            Matrix *src = scene->camera->FUN_00099180()->vf14();
            m = *src;
            m.FUN_0022b9c0();
        }
        Renderer_1f7320 *r = FUN_0027f250();
        r->FUN_0027ffc0(slotC, &m);
    }
    FUN_0027f250()->FUN_00283a10(dt);
}
} // namespace fn_001f7320

