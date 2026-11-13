// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001bc0c0..0x001bddc0 (kind game, layer game, confidence medium), dominant class CExtraRenderingCallback
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0a5b372 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0a5b372 {} using namespace fn_f0a5b372;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0a5b372 {
class Obj_1bc3c0 {
  public:
    char pad[0x18];
    int mValue;
    int Get();
};
struct Triple {
    int a, b, c;
};
class Obj {
    char pad[0x330];
    Triple value;

  public:
    Triple Get();
};
class Obj_1bc4e0 {
  public:
    void DoA_001c3520();
    void DoB_001c35f0();
};
Obj_1bc4e0* __cdecl GetObj_001c3d90();
struct Vec2_1bc530 {
    float x, y;
    float spare;    // FUN_00292cc0 writes three floats through &p (the third lands here, not on the saved ebp)
};
struct Rect_1bc530 {
    float minX;
    float maxY;
    float maxX;
    float minY;
};
struct Mapper_1bc530 {
    void FUN_00292cc0(int arg, Vec2_1bc530* out);
};
struct Inner_1bc530 {
    Mapper_1bc530* FUN_001c19a0();
};
struct Holder_1bc530 {
    Inner_1bc530* inner;
};
Holder_1bc530* FUN_001c3d90();
class X_1bc710 {
  public:
    void Run_001c3850(void*);
};
extern X_1bc710* __cdecl Make_001c3d90();
struct X {
    char pad[0x18];
    unsigned char* a;
    char pad2[8];
    int* b;
    int Get(unsigned char x);
};
class Obj_1bc830 {
  public:
    virtual void Fn0();
    virtual void Release();
};
class Holder_1bc830 {
  public:
    int pad0;
    Obj_1bc830* a;
    Obj_1bc830* b;
    Obj_1bc830* c;
    Obj_1bc830* d;
    Obj_1bc830* e;
    Obj_1bc830* f;
    void Free();
};
struct V3_1bc8a0 {
    float x, y, z;
    void FUN_00011090();
};
struct V4_1bc8a0 {
    float v[4];
};
struct Mat4_1bc8a0 {
    float m[16];
    void FUN_0022b980();
};
struct Corners {
    V3_1bc8a0 pt[2];
};
struct Obj_1bc8a0;
struct List_1bc8a0 {
    Obj_1bc8a0 **begin;
    Obj_1bc8a0 **end;
};
struct Obj_1bc8a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_1bc8a0 *v4();
    virtual void v5();
    virtual int v6();
    char pad04[0x10];
    List_1bc8a0 *children;     // 0x14
    char b18;
    char pad19[0x28 - 0x19];
    V3_1bc8a0 half;            // 0x28
    float f34;
    V3_1bc8a0 pos;             // 0x38
    float dx;           // 0x44
    float dy;           // 0x48
    union {
        Mat4_1bc8a0 mat;       // 0x4c
        struct {
            float dz;
            float f50;
            float f54;
            char b58;
        } c;
    };
    char pad8c[0xcc - 0x8c];
    char bcc;
    void FUN_002fb950(V3_1bc8a0 *out, int i);
    Corners *FUN_002f37c0();
};
extern "C" void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_1bc8a0::*ctor)());
void FUN_001bc530(V4_1bc8a0 *q, V3_1bc8a0 *v);
extern "C++" __declspec(nothrow) void __cdecl FUN_001bc5b0(void *, void *, float);
class CExtraRenderingCallback {
  public:
    virtual void f0();
    int a[6];
    CExtraRenderingCallback();
};


// 0x001bc3c0 FUN_001bc3c0 (4 B): matches/0x001bc3c0.cpp
// sym: ?Get@Obj_1bc3c0@fn_f0a5b372@@QAEHXZ
int Obj_1bc3c0::Get() {
    return mValue;
}


// 0x001bc3e0 FUN_001bc3e0 (33 B): matches/0x001bc3e0.cpp
// sym: ?Get@Obj@fn_f0a5b372@@QAE?AUTriple@2@XZ
Triple Obj::Get() {
    return value;
}


// 0x001bc4e0 FUN_001bc4e0 (42 B): matches/0x001bc4e0.cpp
// sym: ?target@fn_f0a5b372@@YIXPAVObj_1bc4e0@1@@Z
void __fastcall target(Obj_1bc4e0* self) {
    Obj_1bc4e0* saved = self;
    GetObj_001c3d90()->DoA_001c3520();
    GetObj_001c3d90()->DoB_001c35f0();
    ((owners::Thing_1c3770 *)(GetObj_001c3d90()))->FUN_001c3770((hulk_intptr)(Obj_1bc4e0 *)saved);
}

} // namespace fn_f0a5b372

// 0x001bc510 FUN_001bc510 (24 B): matches/0x001bc510.cpp [wrapped: conflict: GetObj]
// sym: _FUN_001bc510
namespace fn_001bc510 {
struct Obj_1bc510 {
    void DoThing_001c4230();
    void Finish_001c3dc0();
};
Obj_1bc510* __cdecl GetObj_001c3d90();
extern "C" void FUN_001bc510(void* /*this, unused: callers pass it (unb4)*/) {
    Obj_1bc510* p = GetObj_001c3d90();
    p->DoThing_001c4230();
    p = GetObj_001c3d90();
    p->Finish_001c3dc0();
}
} // namespace fn_001bc510

namespace fn_f0a5b372 {

// 0x001bc530 FUN_001bc530 (113 B): equivalent/0x001bc530.cpp
// sym: ?FUN_001bc530@fn_f0a5b372@@YAXPAURect_1bc530@1@H@Z @763051e48af7 @w6b0ebfd83bc3
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 8/8; Wine build 606 inputs, 8/8)
// FUN_001bc530 @ 0x001bc530
// Grows the rect (passed in esi) to include the point mapped from arg.
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(Rect_1bc530* rect, hulk_intptr arg)
{
    Vec2_1bc530 p;
    FUN_001c3d90()->inner->FUN_001c19a0()->FUN_00292cc0(arg, &p);
    if (p.x < rect->minX)
        rect->minX = p.x;
    if (p.y > rect->maxY)
        rect->maxY = p.y;
    if (p.x > rect->maxX)
        rect->maxX = p.x;
    if (p.y < rect->minY)
        rect->minY = p.y;
}

} // namespace fn_f0a5b372

// 0x001bc5b0 FUN_001bc5b0 (348 B): equivalent/0x001bc5b0.cpp [wrapped: conflict: FUN_001c3d90]
// sym: _FUN_001bc5b0 @2a1cc770d8af @w440e730a7494
namespace fn_001bc5b0 {
// STATUS: equivalent (tools/equiv.py level 3: 8531 inputs, branch coverage 0/0)
// FUN_001bc5b0 @ 0x001bc5b0
// FUN_001bc5b0 @ 0x001bc5b0
struct Vec3_1bc5b0 {
    float x, y, z;
};

class View {
public:
    void FUN_001c19a0();
};

class Camera {
public:
    View *view;
    Vec3_1bc5b0 *FUN_001c39b0();
    Vec3_1bc5b0 *FUN_001c39a0();
};

Camera *FUN_001c3d90();
struct Rect_1bc5b0;
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(Rect_1bc5b0 *rect, Vec3_1bc5b0 *v);

// equiv-conv: FUN_001bc5b0 eax edi stack
extern "C" void FUN_001bc5b0(void *rect, void *pos, float a)
{
    Camera *cam = FUN_001c3d90();
    cam->view->FUN_001c19a0();
    Vec3_1bc5b0 *d = cam->FUN_001c39b0();
    Vec3_1bc5b0 v;
    v = *((Vec3_1bc5b0 *)pos);
    v.x = a * d->x + v.x;
    v.y = a * d->y + v.y;
    v.z = a * d->z + v.z;
    FUN_001bc530(((Rect_1bc5b0 *)rect), &v);
    float neg = -a;
    v = *((Vec3_1bc5b0 *)pos);
    v.x = neg * d->x + v.x;
    v.y = neg * d->y + v.y;
    v.z = neg * d->z + v.z;
    FUN_001bc530(((Rect_1bc5b0 *)rect), &v);
    d = cam->FUN_001c39a0();
    v = *((Vec3_1bc5b0 *)pos);
    v.x = a * d->x + v.x;
    v.y = a * d->y + v.y;
    v.z = a * d->z + v.z;
    FUN_001bc530(((Rect_1bc5b0 *)rect), &v);
    v = *((Vec3_1bc5b0 *)pos);
    v.x = neg * d->x + v.x;
    v.y = neg * d->y + v.y;
    v.z = neg * d->z + v.z;
    FUN_001bc530(((Rect_1bc5b0 *)rect), &v);
}
} // namespace fn_001bc5b0

namespace fn_f0a5b372 {

// 0x001bc710 FUN_001bc710 (12 B): matches/0x001bc710.cpp
// sym: ?target@fn_f0a5b372@@YGXPAX@Z
void __stdcall target(void* a) {
    X_1bc710* x = Make_001c3d90();
    x->Run_001c3850(a);
}

} // namespace fn_f0a5b372

// 0x001bc720 FUN_001bc720 (12 B): matches/0x001bc720.cpp [wrapped: conflict: Make]
// sym: ?target@fn_001bc720@@YAXPAX@Z
namespace fn_001bc720 {
// Same code shape as 0x001bc710 (propagated; names are from that function)
class X_1bc720 {
  public:
    void Run_001c3e10();
};
extern X_1bc720* __cdecl Make_001c3d90();
void __cdecl target(void* /*this, unused: callers pass it (unb4)*/) {
    Make_001c3d90()->Run_001c3e10();
}
} // namespace fn_001bc720


// 0x001bc730 FUN_001bc730 (159 B): matches/0x001bc730.cpp [wrapped: conflict: Camera; FUN_001c3d90]
// sym: ?FUN_001bc730@fn_001bc730@@YAXXZ
namespace fn_001bc730 {
// FUN_001bc730 @ 0x001bc730
// FUN_001bc730: send the camera orientation (rows: right, -forward-ish, up) to the renderer

struct Matrix {
    float m[16];
    void FUN_0022b980();    // identity
};

struct Camera {
    Matrix view;
};

struct CameraSet {
    Camera *FUN_001c12b0();
};

struct CameraManager_1bc730 {
    CameraSet *set;
};

struct Renderer_1bc730 {
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
    virtual void v15();
    virtual void v16();
    virtual void SetOrientation(int zero, Matrix *m);
};

CameraManager_1bc730 *__cdecl FUN_001c3d90();
struct RendererHolder {
    Renderer_1bc730 *renderer;
};

struct Frame_1bc730 {
    Matrix out;
    int pad[2];
    volatile float tmp;
    Matrix view;
};

void FUN_001bc730()
{
    Frame_1bc730 f;
    f.view = FUN_001c3d90()->set->FUN_001c12b0()->view;
    f.out.FUN_0022b980();
    float *v = f.view.m;
    float *o = f.out.m;
    ((int *)o)[0] = ((int *)v)[0];
    ((int *)o)[1] = ((int *)v)[1];
    ((int *)o)[2] = ((int *)v)[2];
    float nx = -v[8];
    float ny = -v[9];
    f.tmp = -v[10];
    o[4] = nx;
    o[5] = ny;
    ((int *)o)[6] = *(volatile int *)&f.tmp;
    ((int *)o)[8] = ((int *)v)[4];
    ((int *)o)[9] = ((int *)v)[5];
    ((int *)o)[10] = ((int *)v)[6];
    (*(RendererHolder**)&DAT_0052c2ac)->renderer->SetOrientation(0, &f.out);
}
} // namespace fn_001bc730

namespace fn_f0a5b372 {

// 0x001bc800 FUN_001bc800 (21 B): matches/0x001bc800.cpp
// sym: ?Get@X@fn_f0a5b372@@QAEHE@Z
int X::Get(unsigned char x) {
    return b[a[x]];
}


// 0x001bc830 FUN_001bc830 (99 B): matches/0x001bc830.cpp
// sym: ?Free@Holder_1bc830@fn_f0a5b372@@QAEXXZ
void Holder_1bc830::Free() {
    if (f) {
        f->Release();
        f = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (a) {
        a->Release();
        a = 0;
    }
}


// 0x001bc8a0 FUN_001bc8a0 (881 B): equivalent/0x001bc8a0.cpp
// sym: _FUN_001bc8a0 @6195f90fc8bd @w4ed8eaa4ea89
// STATUS: equivalent (tools/equiv.py level 3: 143 inputs, branch coverage 36/36)
// FUN_001bc8a0 @ 0x001bc8a0
// FUN_001bc8a0 @ 0x001bc8a0
// equiv-conv: FUN_001bc530 esi stack
// equiv-conv: FUN_001bc5b0 eax edi stack
extern "C" void FUN_001bc8a0(void * obj_, void *q)
{
    Obj_1bc8a0 * obj = (Obj_1bc8a0 *)obj_;
    if (obj == 0 || !obj->b18)
        return;
    switch (obj->v6()) {
    case 2: {
        V3_1bc8a0 p;
        float t = obj->c.f50;
        if (obj->c.b58)
            t = t - obj->c.f54;
        p = obj->pos;
        ((owners::Vec3_11160 *)&p)->FUN_00011160(t, (const owners::Vec3_11160 *)(V3_1bc8a0 *)((V3_1bc8a0 *)&obj->dx));
        FUN_001bc5b0((V4_1bc8a0 *)((V4_1bc8a0 *)q), (V3_1bc8a0 *)(&p), obj->c.f54);
        p = obj->pos;
        ((owners::Vec3_11160 *)&p)->FUN_00011160(-t, (const owners::Vec3_11160 *)(V3_1bc8a0 *)((V3_1bc8a0 *)&obj->dx));
        FUN_001bc5b0((V4_1bc8a0 *)((V4_1bc8a0 *)q), (V3_1bc8a0 *)(&p), obj->c.f54);
        break;
    }
    case 5: {
        V3_1bc8a0 out;
        for (int i = 0; i < 8; i++) {
            obj->FUN_002fb950(&out, i);
            FUN_001bc530(((V4_1bc8a0 *)q), &out);
        }
        break;
    }
    case 7: {
        float a = obj->f34;
        V3_1bc8a0 *pos = obj->v4();
        FUN_001bc5b0((V4_1bc8a0 *)((V4_1bc8a0 *)q), (V3_1bc8a0 *)pos, a);
        break;
    }
    case 4: {
        struct Frame {
            V3_1bc8a0 pt[2];
            V3_1bc8a0 out;
            V3_1bc8a0 in;
            Mat4_1bc8a0 m;
        } f;
        Corners *src = obj->FUN_002f37c0();
        FUN_00011520(&f.pt[0], 12, 2, &V3_1bc8a0::FUN_00011090);
        f.pt[0] = src->pt[0];
        f.pt[1] = src->pt[1];
        f.m = obj->mat;
        if (!obj->bcc)
            f.m.FUN_0022b980();
        for (int a = 0; a < 2; a++) {
            f.in.x = f.pt[a].x;
            for (int b = 0; b < 2; b++) {
                f.in.y = f.pt[b].y;
                for (int c = 0; c < 2; c++) {
                    f.in.z = f.pt[c].z;
                    ((owners::Mat_22c2b0 *)&(f.m))->FUN_0022c2b0((float *)(V3_1bc8a0 *)(&f.in), (float *)(V3_1bc8a0 *)(&f.out));
                    FUN_001bc530(((V4_1bc8a0 *)q), &f.out);
                }
            }
        }
        break;
    }
    case 6: {
        V3_1bc8a0 lo = *obj->v4();
        V3_1bc8a0 h = obj->half;
        for (int i = 0; i < 4; i += 2) {
            V3_1bc8a0 p;
            p.x = (float)(((double)i - 1.0) * h.x + lo.x);
            double cy = lo.y;
            double cz = lo.z;
            for (int j = 0; j < 4; j += 2) {
                float ty = (float)(((double)j - 1.0) * h.y);
                p.y = (float)(cy + ty);
                for (int k = 0; k < 4; k += 2) {
                    float tz = (float)(((double)k - 1.0) * h.z);
                    p.z = (float)(cz + tz);
                    FUN_001bc530(((V4_1bc8a0 *)q), &p);
                    cz = (double)p.z - tz;
                }
                cy = (double)p.y - ty;
            }
        }
        break;
    }
    default:
        break;
    }
    List_1bc8a0 *list = obj->children;
    if (list != 0) {
        for (Obj_1bc8a0 **it = list->begin; it != list->end; it++)
            FUN_001bc8a0((Obj_1bc8a0 *)(*it), (V4_1bc8a0 *)((V4_1bc8a0 *)q));
    }
}

} // namespace fn_f0a5b372

// 0x001bcc30 FUN_001bcc30 (628 B): equivalent/0x001bcc30.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_001bcc30@Rig_1bcc30@fn_001bcc30@@QAEXXZ @97bcd82fc3a7 @wb2132a48ddb9
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001bcc30 {
// STATUS: equivalent (tools/equiv.py level 3: 20052 inputs, branch coverage 30/30)
// FUN_001bcc30 @ 0x001bcc30
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

struct V3_1bcc30 {
    float x, y, z;
};

struct V4_1bcc30 {
    float v[4];
};

struct Sub;

struct Target_1bcc30 {
    char pad0[0x20];
    Sub *sub;
};

struct Names_1bcc30 {
    int FUN_0027b200(__int64 key);
};

struct Node;

struct Link_1bcc30 {
};

struct Node {
    char pad0[0x74];
    Target_1bcc30 *target;
};

struct Ctl_1bcc30 {
    char pad0[8];
    struct Child_1bcc30 *child;
    int mode;
    char pad10[0x74 - 0x10];
    Target_1bcc30 *target;
};

struct Child_1bcc30 {
    char pad0[0x40];
    int handle;
    char pad44[0x120 - 0x44];
    struct Skel_1bcc30 *skel;
    char pad124[4];
    Link_1bcc30 *link;
};

struct Skel_1bcc30 {
    char pad0[8];
    Names_1bcc30 *names;
    char pad0c[0x1c - 0x0c];
    char *joints;
};

struct Hero_1bcc30 {
    char pad0[0x328];
    Ctl_1bcc30 *ctl;
};

struct Scene_1bcc30 {
    char pad0[0x124];
    Hero_1bcc30 *hero;
    char pad128[0x350 - 0x128];
    bool active;
};

struct World {
    char pad0[0x20];
    Scene_1bcc30 *scene;
};

struct Cursor_1bcc30 {
    void FUN_001c19a0();
};

struct Holder2_1bcc30 {
    char pad0[0x10];
    Sub *sub10;
};


Cursor_1bcc30 **FUN_001c3d90();
// equiv-conv: FUN_001bc530 esi stack
void FUN_001bc530(V4_1bcc30 *q, V3_1bcc30 *v);
extern "C++" __declspec(nothrow) void __cdecl FUN_001bc8a0(void *, void *);
extern "C" void FUN_00096a90(Ctl_1bcc30 *ctl, V3_1bcc30 *out);
struct Lookup_1bcc30 { Holder2_1bcc30 *FUN_001d75c0(int handle); };

class Rig_1bcc30 {
public:
    char pad0[0x1c];
    V4_1bcc30 quat;
    void FUN_001bcc30();
};

struct Frame_1bcc30 {
    Target_1bcc30 *target;
    Ctl_1bcc30 *ctl;
    Rig_1bcc30 *self;
    V3_1bcc30 a;
    V3_1bcc30 b;
    V4_1bcc30 q;
};

void Rig_1bcc30::FUN_001bcc30()
{
    Frame_1bcc30 f;
    Scene_1bcc30 *scene = DAT_004dd700->scene;
    f.self = this;
    (*FUN_001c3d90())->FUN_001c19a0();
    if (!scene->active)
        return;
    Hero_1bcc30 *hero = scene->hero;
    if (hero == 0)
        return;
    f.ctl = hero->ctl;
    if (f.ctl == 0)
        return;
    f.target = f.ctl->target;
    f.q.v[0] = 1.0f;
    f.q.v[2] = -1.0f;
    f.q.v[1] = -1.0f;
    f.q.v[3] = 1.0f;
    if (f.ctl->mode == 1) {
        Child_1bcc30 *child = f.ctl->child;
        if (child != 0) {
            if (child->link != 0) {
                Node *n = ((Node *)((owners::C_1d72e0 *)(child->link))->FUN_001d72e0());
                if (n != 0)
                    f.target = n->target;
            } else if (child->skel != 0) {
                Skel_1bcc30 *skel = child->skel;
                Names_1bcc30 *names = skel->names;
                if (!(DAT_004e22d0 & 1)) {
                    DAT_004e22d0 |= 1;
                    DAT_004e22a0 = FUN_002672f0("Motion_Root", 0, 0);
                    DAT_004e22a8 = FUN_002672f0("Neck", 0, 0);
                    DAT_004e22b0 = FUN_002672f0("Wrist_R", 0, 0);
                    DAT_004e22b8 = FUN_002672f0("Wrist_L", 0, 0);
                    DAT_004e22c0 = FUN_002672f0("Ankle_R", 0, 0);
                    DAT_004e22c8 = FUN_002672f0("Ankle_L", 0, 0);
                }
                __int64 *p = &DAT_004e22a0;
                do {
                    int idx = names->FUN_0027b200(*p);
                    if (idx != 0xffff) {
                        const V3_1bcc30 *src = (const V3_1bcc30 *)(skel->joints + idx * 64 + 0x30);
                        f.b = *src;
                        FUN_001bc530(&f.q, &f.b);
                    }
                    p++;
                } while (p < (__int64 *)&DAT_004e22d0);
            }
        }
    } else if (f.ctl->mode == 5) {
        Child_1bcc30 *child = f.ctl->child;
        if (child != 0) {
            Holder2_1bcc30 *h = ((Lookup_1bcc30*)child)->FUN_001d75c0(child->handle);
            if (h != 0)
                FUN_001bc8a0((Sub *)(h->sub10), (V4_1bcc30 *)(&f.q));
        }
    }
    if (f.target != 0)
        FUN_001bc8a0((Sub *)(f.target->sub), (V4_1bcc30 *)(&f.q));
    f.a.x = 0;
    f.a.y = 0;
    f.a.z = 0;
    FUN_00096a90(f.ctl, &f.a);
    FUN_001bc530(&f.q, &f.a);
    quat = f.q;
}
} // namespace fn_001bcc30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f0a5b372 {

// 0x001bceb0 FUN_001bceb0 (29 B): matches/0x001bceb0.cpp
// sym: ??0CExtraRenderingCallback@fn_f0a5b372@@QAE@XZ
CExtraRenderingCallback::CExtraRenderingCallback() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
}

} // namespace fn_f0a5b372

// 0x001bcef0 FUN_001bcef0 (3155 B): equivalent/0x001bcef0.cpp [wrapped: helper definitions (4 out-of-line function bodies)]
// sym: ?FUN_001bcef0@Fx_1bcef0@fn_001bcef0@@QAEXXZ @b357113b6fea @w095cbf932da9
namespace fn_001bcef0 {
// STATUS: equivalent (tools/equiv.py level 3: 20186 inputs, branch coverage 136/140, incomplete)
// FUN_001bcef0 @ 0x001bcef0
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
extern "C" double __cdecl sqrt(double);
#endif

extern "C" void * __cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

extern char DAT_0049fd74[];
extern char DAT_004c4bb4[];

struct Mat_1bcef0;
struct V3_1bcef0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat_1bcef0 {
    float m[16];
    void FUN_0022b980();
};

struct Item_1bcef0 {
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4();
    virtual void i5(); virtual void i6(); virtual void i7(); virtual void i8(); virtual void i9();
    virtual void i10();
    virtual float v11();
    virtual void v12(float a);
};

struct Group_1bcef0 {
    char pad0[8];
    unsigned char b8;
    char pad9[0x18 - 9];
    unsigned char *f18;
    char pad1c[0x24 - 0x1c];
    Item_1bcef0 **f24;
};

struct Node {
    virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4();
    virtual void n5();
    virtual void v6(int a, int b);
    virtual void n7();
    virtual void v8(int a, int b);
    char pad04[0x44];
    Group_1bcef0 *f48;
};

struct Renderer_1bcef0 {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void v24(V3_1bcef0 *p, V3_1bcef0 *a, V3_1bcef0 *b);
};

struct Dev_1bcef0 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void v13(int a);
    virtual void d14();
    virtual void v15(int a);
    virtual void v16(int a);
    virtual void v17(int a, Mat_1bcef0 *m);
};

struct Wrapper_1bcef0 {
    Dev_1bcef0 *dev;
    void FUN_00293d00(V3_1bcef0 *v);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293c20(float a);
};

struct Gfx {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void e48();
    virtual void e49();
    virtual void e50();
    virtual void e51();
    virtual void e52();
    virtual void e53();
    virtual void e54();
    virtual void e55();
    virtual void e56();
    virtual void e57();
    virtual void e58();
    virtual void e59();
    virtual void v60(int a);
    virtual int v61();
    virtual void v62(int a);
    virtual char v63();
};


struct Holder_1bcef0 {
    Renderer_1bcef0 *FUN_001c19a0();
    Mat_1bcef0 *FUN_001c12c0();
};
Holder_1bcef0 **FUN_001c3d90();
hulk_freg __cdecl FUN_00018a20(float v);
char FUN_00035da0();

struct Obj3c_1bcef0 {
    int FUN_000d6f50();
};

struct Obj8_1bcef0 {
    char FUN_000997a0();
};

class Zone;

struct Ready_1bcef0 {
    int FUN_001d60c0();
};

struct Entity {
    char pad0[0x20];
    int f20;
    char pad24[0xec - 0x24];
    Ready_1bcef0 *ready;
    char padf0[0x114 - 0xf0];
    void *f114;
    char pad118[0x148 - 0x118];
    Entity *f148;
    char pad14c[0x1b0c - 0x14c];
    float f1b0c;
    float f1b10;
    int FUN_001d62d0();
};

struct Target_1bcef0 {
    char pad0[0x8];
    Entity *ent;
    int type;
};

struct Obj124_1bcef0 {
    char pad0[0x12c];
    void *f12c;
    char pad130[0x328 - 0x130];
    Target_1bcef0 *f328;
    char pad32c[0x1fa0 - 0x32c];
    int f1fa0;
};

struct Obj20_1bcef0 {
    char pad0[0x124];
    Obj124_1bcef0 *f124;
    char pad128[0x350 - 0x128];
    char b350;
    char b351;
    void FUN_001bc3e0(V3_1bcef0 *out);
    char FUN_00029a90();
};

struct Dir_1bcef0 {
    char pad0[0x10];
    float x, y, z;
};

struct Obj40 {
    char pad0[4];
    Node *f04;
    Node *f08;
    Node *f0c;
    Node *f10;
    Node *f14;
    struct Dir_1bcef0 *f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    void FUN_001bcc30();
};

struct World {
    char pad0[8];
    Obj8_1bcef0 *f8;
    char pad0c[0x20 - 0xc];
    Obj20_1bcef0 *f20;
    char pad24[0x3c - 0x24];
    Obj3c_1bcef0 *f3c;
    Obj40 *f40;
};

struct Frame_1bcef0 {
    char pad00[3];
    char b13;
    union { volatile float f; float ang; int a; Node *eb; } u4;
    union { Obj40 *p40; float r; int n; } u8;
    V3_1bcef0 v;
    union { Obj20_1bcef0 *o20; float ang2; float arg; } u18;
    V3_1bcef0 P;
    union { volatile float e; int n; Node *eb; } u28;
    union { V3_1bcef0 o3; struct { float A; float padc8; float C; float D; } ac; } u2c;
    union { Renderer_1bcef0 *R; int i; } u3c;
    float k;
    V3_1bcef0 vb4;
    V3_1bcef0 va8;
    void *self;
    union { char b; unsigned int dw; } u60;
    int prevI;
    union { Mat_1bcef0 M2; V3_1bcef0 c[4]; } u68;
    float arr2[4];
    Mat_1bcef0 mat;
};

static float K0557() { return 0.5569999814033508f; }
static float K003() { return 0.030000001192092896f; }
static float K003975() { return 0.039750002324581146f; }

static __forceinline void ApplyGroup(Node *n, char *on)
{
    Group_1bcef0 *g = n->f48;
    if (g) {
        unsigned char cnt = g->b8;
        for (unsigned char i = 0; i < cnt; i++) {
            Item_1bcef0 *it = g->f24[g->f18[i]];
            if (it) {
                if (*on)
                    it->v12(1.0f);
                else
                    it->v12(0.0f);
            }
        }
        n->v6(0, 0);
    }
}

class Fx_1bcef0 {
public:
    void FUN_001bc730();
    void FUN_001bcef0();
};

void Fx_1bcef0::FUN_001bcef0()
{
    Frame_1bcef0 f;
    f.self = this;
    if ((*(unsigned char*)&DAT_004dd888))
        return;
    World *w = DAT_004dd700;
    Obj3c_1bcef0 *p3c = w->f3c;
    if (!w->f8->FUN_000997a0())
        return;
    if (!((owners::Thing_d6fd0 *)p3c)->FUN_000d6fd0())
        return;
    if ((p3c->FUN_000d6f50() & 0xfffffc7f) == 0)
        return;

    f.u60.b = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    f.prevI = DAT_0052c2a8->v61();
    DAT_0052c2a8->v60(1);
    f.u18.o20 = w->f20;
    f.u8.p40 = w->f40;
    Holder_1bcef0 *h = *FUN_001c3d90();
    f.u3c.R = h->FUN_001c19a0();
    f.u8.p40->FUN_001bcc30();
    Obj20_1bcef0 *o20 = f.u18.o20;
    if (o20->b351) {
        Node *o14 = f.u8.p40->f14;
        if (o14) {
            Mat_1bcef0 *m = h->FUN_001c12c0();
            f.mat = *m;
            o20->FUN_001bc3e0(&f.v);
            ((owners::Obj_22d210 *)&(f.v))->FUN_0022d210((owners::Obj_22d210 *)(Mat_1bcef0 *)(&f.mat));
            f.v.z = 0.0f;
            f.v.FUN_0022d110();
            f.u8.r = FUN_00018a20(f.v.y);
            f.u4.f = f.u8.r * 0.636619747f - 1.0f;
            f.u4.f = f.u4.f < 0.0f ? -f.u4.f : f.u4.f;
            hulk_freg s = 1.0f - f.u4.f * 0.25f;
            f.v.x = f.v.x * s;
            f.v.y = s * f.v.y;
            if (f.v.x > 0.0f)
                f.u8.r = -f.u8.r;
            f.u68.M2.FUN_0022b980();
            ((owners::Mat_22bab0 *)&(f.u68.M2))->FUN_0022bab0(f.u8.r);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v15(0);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v13(0);
            f.v.z = (*(float*)&DAT_004c4be4);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v17(0, &f.u68.M2);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293da0((*(float*)&DAT_004c4be0), (*(float*)&DAT_004c4be0), (*(float*)&DAT_004c4be0));
            o14->v8(0, 0);
            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v16(0);
        }
    } else if (o20->b350) {
        Obj124_1bcef0 *p124 = o20->f124;
        if (p124) {
            Target_1bcef0 *t = p124->f328;
            char ok = FUN_00035da0();
            if (t && (ok || p124->f1fa0 == 2 || p124->f1fa0 == 1)) {
                f.k = 1.0f;
                f.b13 = 0;
                int ty = t->type;
                if (ty == 1) {
                    Entity *ent = t->ent;
                    if (ent) {
                        if (ent->f1b10 > 0.0f)
                            f.k = ent->f1b0c / ent->f1b10;
                    }
                } else if (ty == 5) {
                    Entity *ent = t->ent;
                    if (ent) {
                        Entity *e2 = ent->f148;
                        if (e2) {
                            if (e2->f1b10 > 0.0f)
                                f.k = e2->f1b0c / e2->f1b10;
                        } else {
                            f.u4.a = ent->FUN_001d62d0();
                            f.u28.n = ent->ready->FUN_001d60c0();
                            if (f.u28.n > 0)
                                f.k = (float)f.u4.a / f.u28.n;
                            void *r = ent->f114;
                            if (r == 0 || r == p124->f12c)
                                f.b13 = 1;
                            else
                                f.b13 = 0;
                        }
                    }
                } else if (ty == 7) {
                    Entity *ent = t->ent;
                    if (ent) {
                        f.k = 1.0f;
                        if (ent->f20 <= 0)
                            f.k = 0.0f;
                        f.b13 = 1;
                    }
                }

                Obj40 *p40 = f.u8.p40;
                f.u2c.ac.A = p40->f1c;
                hulk_freg Bp = p40->f20;
                f.u2c.ac.C = p40->f24;
                f.u2c.ac.D = p40->f28;
                static float lim0 = K0557();
                if (f.u2c.ac.A < -lim0)
                    f.u2c.ac.A = -lim0;
                if (f.u2c.ac.C > lim0)
                    f.u2c.ac.C = lim0;
                static float lim1 = K0557();
                if (Bp > lim1)
                    Bp = lim1;
                if (f.u2c.ac.D < -lim1)
                    f.u2c.ac.D = -lim1;
                static float lim2 = K003();
                f.u28.e = f.u2c.ac.C - f.u2c.ac.A;
                hulk_freg u = f.u28.e - (lim2 + lim2);
                if (u < 0.0f) {
                    hulk_freg hh = u * 0.5f;
                    f.u2c.ac.A = f.u2c.ac.A + hh;
                    f.u2c.ac.C = f.u2c.ac.C - hh;
                    f.u28.e = f.u2c.ac.C - f.u2c.ac.A;
                }
                static float lim3 = K003975();
                f.u4.f = Bp - f.u2c.ac.D;
                hulk_freg v2 = f.u4.f - (lim3 + lim3);
                if (v2 < 0.0f) {
                    Bp = Bp - v2 * 0.5f;
                    double Dn = v2 * 0.5f + f.u2c.ac.D;
                    f.u2c.ac.D = (float)Dn;
                    f.u4.f = Bp - Dn;
                }
                f.u68.c[0].x = f.u2c.ac.A;
                f.u68.c[0].y = Bp;
                f.u68.c[0].z = 0.0f;
                f.u68.c[1].x = f.u2c.ac.C;
                f.u68.c[1].y = Bp;
                f.u68.c[1].z = 0.0f;
                f.u68.c[2].x = f.u2c.ac.C;
                f.u68.c[2].y = f.u2c.ac.D;
                f.u68.c[2].z = 0.0f;
                f.u68.c[3].x = f.u2c.ac.A;
                f.u68.c[3].y = f.u2c.ac.D;
                f.u68.c[3].z = 0.0f;

                Node *n0c = p40->f0c;
                if (n0c) {
                ApplyGroup(n0c, &f.b13);
                if (f.u28.e > 1.0f)
                    f.u28.e = 1.0f;
                if (f.u4.f > 0.7f)
                    f.u4.f = 0.7f;
                f.arr2[0] = f.u28.e * 40.0f;
                hulk_freg ff = f.u4.f;
                f.u4.ang = 1.57079637f;
                f.arr2[1] = ff * 30.0f;
                f.arr2[2] = f.u28.e * 40.0f;
                f.arr2[3] = ff * 30.0f;
                for (int i = 0; i < 4; i++) {
                    f.v = f.u68.c[i];
                    int j = (i + 1) % 4;
                    f.v.x = (f.v.x + f.u68.c[j].x) * 0.5f;
                    f.v.y = (f.v.y + f.u68.c[j].y) * 0.5f;
                    f.v.z = (f.v.z + f.u68.c[j].z) * 0.5f;
                    f.u3c.R->v24(&f.v, &f.vb4, &f.u2c.o3);
                    f.va8.x = f.u2c.o3.x - f.vb4.x;
                    f.va8.y = f.u2c.o3.y - f.vb4.y;
                    f.va8.z = f.u2c.o3.z - f.vb4.z;
                    f.va8.FUN_0022d110();
                    f.P.x = f.va8.x * 0.01f + f.vb4.x;
                    f.P.y = f.va8.y * 0.01f + f.vb4.y;
                    f.P.z = f.va8.z * 0.01f + f.vb4.z;
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v15(0);
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293d00(&f.P);
                    ((Fx_1bcef0 *)f.self)->FUN_001bc730();
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293c20(f.u4.ang);
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293da0(0.004f, 0.004f, f.arr2[i] * 0.004f);
                    n0c->v8(0, 0);
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v16(0);
                    f.u4.ang = f.u4.ang + 1.57079637f;
                }
                }

                Node *n04 = f.u8.p40->f04;
                f.u28.eb = n04;
                Renderer_1bcef0 *R2;
                if (n04) {
                    ApplyGroup(n04, &f.b13);
                    f.u4.a = 0;
                    if (f.u18.o20->FUN_00029a90()) {
                        Node *n08 = f.u8.p40->f08;
                        f.u4.eb = n08;
                        if (n08)
                            ApplyGroup(n08, &f.b13);
                    }
                    Dir_1bcef0 *g18 = f.u8.p40->f18;
                    R2 = f.u3c.R;
                    f.u18.ang2 = 0.0f;
                    V3_1bcef0 *cp = &f.u68.c[0];
                    int cnt = 4;
                    do {
                        R2->v24(cp, &f.va8, &f.u2c.o3);
                        f.vb4.x = f.u2c.o3.x - f.va8.x;
                        f.vb4.y = f.u2c.o3.y - f.va8.y;
                        f.vb4.z = f.u2c.o3.z - f.va8.z;
                        f.vb4.FUN_0022d110();
                        f.P.x = f.vb4.x * 0.01f + f.va8.x;
                        f.P.y = f.vb4.y * 0.01f + f.va8.y;
                        f.P.z = f.vb4.z * 0.01f + f.va8.z;
                        (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v15(0);
                        (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293d00(&f.P);
                        ((Fx_1bcef0 *)f.self)->FUN_001bc730();
                        (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293c20(f.u18.ang2);
                        (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293da0(0.004f, 0.004f, 0.004f);
                        if (g18) {
                            f.v.x = -g18->x;
                            f.v.y = -g18->y;
                            f.v.z = -g18->z;
                            (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
                        }
                        if (f.u4.eb)
                            f.u4.eb->v8(0, 0);
                        f.u28.eb->v8(0, 0);
                        (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v16(0);
                        f.u18.ang2 = f.u18.ang2 + 1.57079637f;
                        cp++;
                    } while (--cnt != 0);
                } else {
                    R2 = f.u3c.R;
                }

                Node *n10 = f.u8.p40->f10;
                if (n10) {
                    Group_1bcef0 *g = n10->f48;
                    if (g) {
                        f.u8.n = g->b8;
                        f.u3c.i = 0;
                        if (g->b8 != 0) {
                            do {
                                Item_1bcef0 *it = g->f24[g->f18[(unsigned char)f.u3c.i]];
                                if (it) {
                                    if (FUN_00344e74(it, 0, DAT_0049fd74, DAT_004c4bb4, 0)) {
                                        f.u18.arg = (it->v11() - 1.0f - 1.0f) * (1.0f - f.k);
                                        it->v12(f.u18.arg);
                                    } else if (f.b13) {
                                        it->v12(1.0f);
                                    } else {
                                        it->v12(0.0f);
                                    }
                                }
                                f.u3c.i++;
                            } while ((unsigned int)f.u3c.i < (unsigned int)f.u8.n);
                        }
                        n10->v6(0, 0);
                    }
                    f.v.x = f.u68.c[2].x;
                    f.v.y = f.u68.c[2].y;
                    f.v.z = f.u68.c[2].z;
                    f.v.x = (f.v.x + f.u68.c[3].x) * 0.5f;
                    f.v.y = (f.v.y + f.u68.c[3].y) * 0.5f;
                    f.v.z = (f.v.z + f.u68.c[3].z) * 0.5f;
                    R2->v24(&f.v, &f.va8, &f.u2c.o3);
                    f.vb4.x = f.u2c.o3.x - f.va8.x;
                    f.vb4.y = f.u2c.o3.y - f.va8.y;
                    f.vb4.z = f.u2c.o3.z - f.va8.z;
                    f.vb4.FUN_0022d110();
                    f.P.x = f.vb4.x * 0.01f + f.va8.x;
                    f.P.y = f.vb4.y * 0.01f + f.va8.y;
                    f.P.z = f.vb4.z * 0.01f + f.va8.z;
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v15(0);
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293d00(&f.P);
                    ((Fx_1bcef0 *)f.self)->FUN_001bc730();
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->FUN_00293da0(0.004f, 0.004f, 0.004f);
                    n10->v8(0, 0);
                    (*(Wrapper_1bcef0**)&DAT_0052c2ac)->dev->v16(0);
                }
            }
        }
    }
    DAT_0052c2a8->v62(f.u60.dw);
    DAT_0052c2a8->v60(f.prevI);
}
} // namespace fn_001bcef0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bdb90 FUN_001bdb90 (523 B): equivalent/0x001bdb90.cpp [wrapped: conflict: World]
// sym: ?FUN_001bdb90@Widget_1bdb90@fn_001bdb90@@QAEXXZ @6f85a5a6b770 @wd166407f531f
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_001bdb90 {
// STATUS: equivalent (tools/equiv.py level 3: 19957 inputs, branch coverage 32/32)
// FUN_001bdb90 @ 0x001bdb90
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



namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class CompositeDrawable_1bdb90;
class Locator_1bdb90;
}

class Res_1bdb90 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Composite_1bdb90 : public Res_1bdb90 {
public:
    void FUN_002998d0(int v);
};

class Inventory_1bdb90 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_1bdb90 *get(void *caster, unsigned __int64 key);
};

struct InvHolder {
    char pad0[0xaa0];
    Inventory_1bdb90 *inv;
};

struct Flags_1bdb90 {
    char pad0[0x32];
    char b32;
};

struct Holder_1bdb90 {
};

struct World {
    char pad0[0x54];
    Holder_1bdb90 *holder;
};

extern "C" int __cdecl FUN_00266da0(hulk_intptr mode);

class Widget_1bdb90 {
public:
    char pad0[4];
    Res_1bdb90 *r4;
    Res_1bdb90 *r8;
    Res_1bdb90 *rc;
    Res_1bdb90 *r10;
    Res_1bdb90 *r14;
    Res_1bdb90 *r18;
    void FUN_001bdb90();
};

void Widget_1bdb90::FUN_001bdb90()
{
    struct Frame {
        char caster[4];
        int saved;
    } f;

    f.saved = FUN_00266da0(0x11);
    Inventory_1bdb90 *inv = ((InvHolder *)((owners::Target_862a0 *)(DAT_004dd700->holder))->FUN_000862a0())->inv;
    Res_1bdb90 *r;
    // the original loads the inventory's vptr before each key lookup and the slot after it
    typedef Res_1bdb90 *(__fastcall *GetFn)(Inventory_1bdb90 *, int, void *, unsigned __int64);
    void **vtable;
    void *caster;
    unsigned __int64 key;

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bfc), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r4)
        r4->Release();
    r4 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf8), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r8)
        r8->Release();
    r8 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf4), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (rc)
        rc->Release();
    rc = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf0), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r10)
        r10->Release();
    r10 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bec), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r14)
        r14->Release();
    r14 = r;

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::Locator_1bdb90>;
    key = FUN_002672f0((*(const char**)&DAT_004c4be8), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r18)
        r18->Release();
    r18 = r;

    ((Flags_1bdb90 *)((owners::Obj_86290 *)(DAT_004dd700->holder))->FUN_00086290())->b32 = 0;
    FUN_00266da0(f.saved);
}
} // namespace fn_001bdb90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

// 0x001bdda0 CExtraRenderingCallback::vfunc_0 (5 B): not yet verified
