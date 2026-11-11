// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00195100..0x00196220 (kind game, layer game, confidence medium), dominant class hulkfight::motion::ProjectileEffect
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c42f35 {
#define TREE_TU_END }
namespace fn_f6c42f35 {} using namespace fn_f6c42f35;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6c42f35 {
class Action_195100 {
  public:
    virtual void F();
    virtual void G();
    char pad[0x18];
    Action_195100();
};
class FireProjectileAction_195100 : public Action_195100 {
  public:
    int a;
    Action_195100* b;
    int c;
    int d;
    int e;
    int f;
    FireProjectileAction_195100(int x, Action_195100* p);
    virtual void F();
    virtual void G();
};
class Ref_195150 {
  public:
    virtual void a();
    virtual void Release();
};
extern int hulk_at_0041b3d8;
class FireProjectileAction {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int m1c;
    Ref_195150* m20;
    int m24;
    Ref_195150* m28;
    Ref_195150* m2c;
    void clean();
};


// 0x00195100 FUN_00195100 (80 B): matches/0x00195100.cpp
// sym: ??0FireProjectileAction_195100@fn_f6c42f35@@QAE@HPAVAction_195100@1@@Z
FireProjectileAction_195100::FireProjectileAction_195100(int x, Action_195100* p) : Action_195100() {
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (p)
        p->F();
    if (b)
        b->G();
    b = p;
}


// 0x00195150 FUN_00195150 (74 B): matches/0x00195150.cpp
// sym: ?clean@FireProjectileAction@fn_f6c42f35@@QAEXXZ
void FireProjectileAction::clean() {
    vptr = (hulk_intptr)&hulk_at_0041b3d8;
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
    ((fight::Action *)this)->FUN_002326a0();
}

} // namespace fn_f6c42f35

// 0x001951a0 hulkfight::motion::FireProjectileAction::vfunc_3 (238 B): equivalent/0x001951a0.cpp [wrapped: conflict: hulkfight::motion::FireProjectileAction]
// sym: ?vfunc_3@FireProjectileAction@motion@hulkfight@fn_001951a0@@UAE_NII@Z
namespace fn_001951a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::motion::FireProjectileAction::vfunc_3 @ 0x001951a0
struct Ref_1951a0 { virtual void AddRef() = 0; virtual void Release() = 0; unsigned reserved; void* data; };
struct Lookup_1951a0 { unsigned FUN_0027b200(unsigned,unsigned); };
struct ActorInfo_1951a0 { char pad[0x74]; void* value; };
struct Actor_1951a0 { ActorInfo_1951a0* FUN_001d72e0(); Ref_1951a0* FUN_001d68d0(); };
struct World { char pad[0x120]; Ref_1951a0* object; Actor_1951a0* FUN_00035ef0(int); };
struct Context { World* FUN_00059a30(); };
struct Owner_1951a0 { Context* FUN_000592a0(); };
void __cdecl FUN_000188e0(Actor_1951a0**, Actor_1951a0*);
void __cdecl FUN_00037510(Ref_1951a0**, Ref_1951a0*);
struct Config_1951a0 { char pad[0x2c]; float duration; int index; unsigned unused; unsigned key1; unsigned key2; };
namespace hulkfight { namespace motion {
struct FireProjectileAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Config_1951a0* config; Owner_1951a0* owner; float rate; Actor_1951a0* actor; Ref_1951a0* object; unsigned id;
};
bool FireProjectileAction::vfunc_3(unsigned,unsigned) {
 if (!owner) return false;
 if (config->duration > 0.0f) rate = 1.0f / config->duration;
 Context* context = owner->FUN_000592a0();
 World* world = context->FUN_00059a30();
 Ref_1951a0* next = world->object;
 if(next) next->AddRef();
 if(object) object->Release();
 object = next;
 int index = config->index;
 if(index >= 0 && index < 8) {
 Actor_1951a0* found = world->FUN_00035ef0(index);
 if(found) {
 if(!found->FUN_001d72e0() || !found->FUN_001d72e0()->value) FUN_000188e0(&actor,found);
 Ref_1951a0* r = found->FUN_001d68d0();
 FUN_00037510(&object,r);
 }
 }
 Ref_1951a0* current = object;
 if(current) {
 unsigned a = config->key1; unsigned b = config->key2;
 Lookup_1951a0* lookup = (Lookup_1951a0*)current->data;
 if(a | b) {
 id = lookup->FUN_0027b200(a,b);
 if(id == 0xffff) id = 0;
 }
 }
 return true;
}
}}
} // namespace fn_001951a0


// 0x00195290 FUN_00195290 (708 B): equivalent/0x00195290.cpp [wrapped: conflict: World]
// sym: ?FUN_00195290@fn_00195290@@YA_NPAUV3_195290@1@PAPAX1000PAPAUShape_195290@1@PAUHandle_195290@1@DPADH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00195290 {
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 34/42, incomplete)
// FUN_00195290 @ 0x00195290
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


struct V3_195290 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Ent_195290;

struct Shape_195290 {
    char pad0[8];
    Ent_195290 *ent;           // 8
    int kind;           // 0xc
};

struct Node {
    char pad0[0x18];
    Shape_195290 *shape;
};

struct Rec_195290 {
    float t;
    Node *node;
    float c;
};

struct HitList_195290 {
    int count;
    char pad4[4];
    Rec_195290 *recs;          // 8
};

struct Ent_195290 {
};

struct Probe_195290 {
    char pad0[0x128];
    Ent_195290 *ent128;
    void FUN_000368d0(int v);
    void FUN_00035fa0(int v);
};

struct Handle_195290 {
    char pad0[8];
    Probe_195290 *probe;       // 8
    int kind;           // 0xc
};

struct Scene_195290 {
    bool FUN_002ee140(HitList_195290 *list, V3_195290 *origin, V3_195290 *end, int z);
};

struct Caster_195290 {
    bool FUN_00201e00(V3_195290 *origin, V3_195290 *end, int mask, V3_195290 *hit, V3_195290 *normal, void **out1, void **out2);
};

struct Sub10_195290 {
    char pad0[8];
    Scene_195290 *scene;
};

struct World {
    char pad0[0x10];
    Sub10_195290 *sub10;
    char pad14[0x10];
    Caster_195290 *caster;     // 0x24
};

extern "C" HitList_195290 *FUN_00202f00();
extern "C" void __cdecl FUN_002f1ce0(V3_195290 *origin, float c, V3_195290 *normal, Shape_195290 **slot);

// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
bool FUN_00195290(V3_195290 *self, void **out2, void **out1, V3_195290 *origin, V3_195290 *end, V3_195290 *normal, Shape_195290 **shapeOut,
                  Handle_195290 *h, char flag, char *flagOut, int g)
{
    World *w = DAT_004dd700;
    bool hit = w->caster->FUN_00201e00(origin, end, 1, self, normal, out1, out2);
    float dist = 3.4028235e38f;
    if (hit) {
        float ax = self->x;
        float ay = self->y;
        float az = self->z;
        double dx = ax - origin->x;
        double dy = ay - origin->y;
        double dz = az - origin->z;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }
    HitList_195290 *list = FUN_00202f00();
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 0;
    DAT_00554c18 = g;
    Scene_195290 *scene = w->sub10->scene;
    Probe_195290 *obj = 0;
    if (h != 0 && h->kind == 1) {
        obj = h->probe;
        if (obj != 0) {
            obj->FUN_000368d0(0);
            obj->FUN_00035fa0(0);
        }
    }
    if (scene->FUN_002ee140(list, origin, end, 0)) {
        int n = list->count;
        struct Frame {
            Shape_195290 *slot;
            Rec_195290 rec;
        } f;
        for (int i = 0; i < n; i++) {
            Rec_195290 *r = &list->recs[i];
            f.rec.t = r->t;
            f.rec.node = r->node;
            f.rec.c = r->c;
            Node *node = f.rec.node;
            Shape_195290 *shape = node->shape;
            f.slot = shape;
            int kind = shape->kind;
            bool process = true;
            if (kind == 1) {
                if (shape == (Shape_195290 *)h)
                    process = false;
            } else if (kind == 5) {
                Ent_195290 *ent = shape->ent;
                if (ent == 0) {
                    process = false;
                } else if (obj != 0) {
                    if (ent == obj->ent128) {
                        process = false;
                    } else {
                        for (int j = 0; j < 8; j++) {
                            if (((Ent_195290 *)((owners::C_35ef0 *)obj)->FUN_00035ef0((hulk_intptr)j)) == ent) {
                                process = false;
                                break;
                            }
                        }
                        node = f.rec.node;
                        shape = f.slot;
                    }
                }
            }
            if (!process)
                continue;
            if (obj != 0 && flag != 0) {
                if (((owners::Thing_35c30 *)obj)->FUN_00035c30((hulk_intptr)(Shape_195290 *)shape))
                    *flagOut = 1;
                else
                    ((owners::Queue_35c70 *)obj)->FUN_00035c70((hulk_intptr)(Shape_195290 *)shape);
            }
            if (f.rec.t > 0.0f && f.rec.t < dist) {
                Shape_195290 *shape2 = node->shape;
                *self = *end;
                self->x = self->x - origin->x;
                self->y = self->y - origin->y;
                self->z = self->z - origin->z;
                self->FUN_0022d110();
                float t = f.rec.t;
                double px = self->x * t;
                self->x = (float)px;
                double py = self->y * t;
                self->y = (float)py;
                double pz = self->z * t;
                volatile float tz = (float)pz;
                self->z = (float)pz;
                self->x = (float)(px + origin->x);
                self->y = (float)(py + origin->y);
                self->z = tz + origin->z;
                f.slot = 0;
                FUN_002f1ce0(origin, f.rec.c, normal, &f.slot);
                *shapeOut = shape2;
                hit = true;
            }
            break;
        }
    }
    if (obj != 0) {
        obj->FUN_00035fa0(1);
        obj->FUN_000368d0(1);
    }
    return hit;
}
} // namespace fn_00195290
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00195560 FUN_00195560 (855 B): equivalent/0x00195560.cpp [wrapped: conflict: World]
// sym: ?FUN_00195560@fn_00195560@@YA_NPAUV3_195560@1@PAUSrc_195560@1@0HPAVMgr_195560@1@20MMHHDMD@Z
namespace fn_00195560 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 42/42)
// FUN_00195560 @ 0x00195560
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

struct V3_195560 {
    float x, y, z;
};

class RefObj_195560 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Request {
    char pad0[8];
    V3_195560 target;             // 0x08
    char pad14[4];
    V3_195560 aim;                // 0x18
    char pad24[4];
    V3_195560 pos;                // 0x28
    char pad34[4];
    float xScaled;         // 0x38
    float yScaled;         // 0x3c
    float zScaled;         // 0x40
    char pad44[0x4c - 0x44];
    RefObj_195560 *p4c;
    RefObj_195560 *p50;
    int r54;
    char pad58[0x78 - 0x58];
    float val;             // 0x78
    int a6;                // 0x7c
    float one;             // 0x80
    RefObj_195560 *p84;
    char pad88[8];
    char pad90[8];
    Request *FUN_00059820();
    void FUN_00059300();
};

class CFightParamsCollision_195560 : public RefObj_195560 {
public:
    char pad04[0xb0 - 4];
    CFightParamsCollision_195560 *FUN_000598e0(int id, Request *r);
};

struct Sub_195560 {
    char data[0x40];
    char FUN_00231e80(struct Res_195560 *r);
};

class Res_195560 {
public:
    void FUN_00231ad0(Sub_195560 *sub, CFightParamsCollision_195560 *e, int v);
};

class Mgr_195560 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Res_195560 *v8(CFightParamsCollision_195560 *e, int z);
};

struct Inner_195560 {
    char pad0[0x1b0];
    int f1b0;
};

struct Obj_195560 {
    char pad0[0x10];
    int *f10;
    char pad14[0xdc - 0x14];
    Sub_195560 sub;
    Inner_195560 *f11c;
    char pad120[0x12c - 0x120];
    RefObj_195560 *f12c;
    char FUN_000360f0();
    void FUN_00043350(float v, RefObj_195560 *r, int a, float one, int b, int c);
    void FUN_00043ae0(int a, V3_195560 *b, float scale, int d, float val, int e, int f, int g, int h);
};

struct Src_195560 {
    char pad0[8];
    Obj_195560 *obj;
};

struct List_195560 {
};

struct World {
    char pad0[0x44];
    List_195560 *list;
};

extern "C" void *FUN_0008d690(unsigned int size);
extern "C" int __cdecl FUN_00266da0(int v);
void __cdecl FUN_00018810(RefObj_195560 **slot, RefObj_195560 *ref);

struct Frame_195560 {
    char pad0[3];
    char same;             // 0xf
    float val;             // 0x10
    Obj_195560 *o;                // 0x14
    int ctx;               // 0x18
    Request x;             // 0x1c
};

// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
bool FUN_00195560(V3_195560 *self, Src_195560 *src, V3_195560 *b, int id, Mgr_195560 *m1, Mgr_195560 *m2, V3_195560 *c, float scale, float f5,
                  int a6, int a7, char a8, float f9, char a10)
{
    Frame_195560 f;
    Obj_195560 *esi = src->obj;
    Obj_195560 *o = ((Obj_195560 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->list))->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    f.o = o;
    f.same = 0;
    if (esi == 0)
        return false;
    if (a8) {
        if (esi->f11c->f1b0 == o->f11c->f1b0)
            return false;
    }
    if (*esi->f10 == id)
        return false;
    f.val = f5;
    if (o) {
        if (esi->f11c->f1b0 == o->f11c->f1b0) {
            f.val = f5 * f9;
            f.same = 1;
        }
    }
    if (esi->FUN_000360f0()) {
        esi->FUN_00043350(f.val, o ? o->f12c : 0, 0, 1.0f, 0, 0);
        return true;
    }

    f.ctx = FUN_00266da0(0xd);
    f.x.FUN_00059820();
    f.x.yScaled = self->y * scale;
    f.x.xScaled = self->x * scale;
    f.x.zScaled = self->z * scale;
    f.x.target = *b;
    f.x.aim = *c;
    f.x.pos = *self;
    f.x.r54 = a7;
    f.x.a6 = a6;
    f.x.val = f.val;
    f.x.one = 1.0f;
    if (f.o)
        FUN_00018810(&f.x.p4c, f.o->f12c);
    RefObj_195560 *r = esi->f12c;
    if (r)
        r->AddRef();
    if (f.x.p50)
        f.x.p50->Release();
    f.x.p50 = r;

    if (m1) {
        void *mem = FUN_0008d690((int)sizeof(CFightParamsCollision_195560));
        CFightParamsCollision_195560 *e = 0;
        if (mem)
            e = ((CFightParamsCollision_195560 *)mem)->FUN_000598e0(*esi->f10, &f.x);
        e->AddRef();
        Res_195560 *res = m1->v8(e, 0);
        bool use;
        if (a10)
            use = res != 0 && f.same != 0;
        else
            use = res != 0;
        if (use) {
            res->FUN_00231ad0(&esi->sub, e, -1);
        } else {
            esi->FUN_00043ae0(0, b, scale, a7, f.val, 0, 0, 0, 0);
        }
        e->Release();
    } else {
        esi->FUN_00043ae0(0, b, scale, a7, f.val, 0, 0, 0, 0);
    }

    Obj_195560 *p = f.o;
    if (p && m2) {
        void *mem = FUN_0008d690((int)sizeof(CFightParamsCollision_195560));
        CFightParamsCollision_195560 *e = 0;
        if (mem)
            e = ((CFightParamsCollision_195560 *)mem)->FUN_000598e0(id, &f.x);
        e->AddRef();
        Res_195560 *res = m2->v8(e, 0);
        if (res) {
            if (!p->sub.FUN_00231e80(res))
                res->FUN_00231ad0(&p->sub, e, -1);
        }
        e->Release();
    }
    f.x.FUN_00059300();
    FUN_00266da0(f.ctx);
    return true;
}
} // namespace fn_00195560
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001958c0 FUN_001958c0 (455 B): equivalent/0x001958c0.cpp [wrapped: conflict: World]
// sym: ?FUN_001958c0@fn_001958c0@@YA_NHPAUHolder_1958c0@1@HHHHPAUV3_1958c0@1@MMHH@Z
namespace fn_001958c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 30/30)
// FUN_001958c0 @ 0x001958c0
// FUN_001958c0 @ 0x001958c0
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

struct V3_1958c0 {
    float x, y, z;
};

struct Tag_1958c0 {
    char pad00[0x1b0];
    int kind;
};

struct Ref12c {
    char pad00[0x12c];
    int id;
};

struct Entity {
    char pad00[0x114];
    int f114;
    char pad118[0x148 - 0x118];
    Ref12c *f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    bool FUN_001d6980();
    void FUN_001d82d0();
    bool FUN_001d7300();
    void FUN_001d6ec0(int a, int b, int c);
    void FUN_001d86d0(V3_1958c0 *v, int a);
};

struct Info_1958c0 {
    char pad00[0x11c];
    Tag_1958c0 *tag;
    char pad120[0x128 - 0x120];
    Entity *f128;
    int f12c;
};

struct Scale_1958c0 {
    float FUN_001dddf0();
};

struct Mgr_1958c0 {
};

struct World {
    char pad00[0xc];
    Scale_1958c0 *scale;
    char pad10[0x44 - 0x10];
    Mgr_1958c0 *mgr;
};

struct Holder_1958c0 {
    char pad00[8];
    Entity *entity;
    char pad0c[0x70 - 0xc];
    int f70;
};


// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
extern bool FUN_00195560(V3_1958c0 *a6, int a0, int a4, int id, int a2, int a3, int a5, float a7, float a8, int a9, int a10, int z0, float one, int z1);

// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
bool FUN_001958c0(int id, Holder_1958c0 *h, int a2, int a3, int a4, int a5, V3_1958c0 *a6, float a7, float a8, int a9, int a10)
{
    Entity *e = h->entity;
    if (!e)
        return false;
    if (e->f148)
        return FUN_00195560(a6, e->f148->id, a4, id, a2, a3, a5, a7, a8, a9, a10, 0, 1.0f, 0);

    Info_1958c0 *p = ((Info_1958c0 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->mgr))->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    if (p) {
        if (e == p->f128)
            return false;
        for (int i = 0; i < 8; i++) {
            if (e == ((Entity *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)i)))
                return false;
        }
        int kind = p->tag->kind;
        if (e->f198 == kind)
            a8 = a8 * e->f19c;
        if (kind == 2)
            a8 = DAT_004dd700->scale->FUN_001dddf0() * a8;
    }
    if (e->FUN_001d6980())
        return false;
    e->FUN_001d82d0();
    if (a8 > 0.0f) {
        Info_1958c0 *q = ((Info_1958c0 *)((owners::ThisWrap_00059c10 *)(DAT_004dd700->mgr))->FUN_00059c10((void *)(hulk_uintptr)(int)id));
        int v = q ? q->f12c : 0;
        e->FUN_001d6ec0((int)a8, v, 0);
    }
    if (e->FUN_001d7300() && e->f114 == 0 && h->f70 != 0 && a7 != 0.0f) {
        V3_1958c0 v = *a6;
        v.x = v.x * a7;
        v.y = v.y * a7;
        v.z = v.z * a7;
        e->FUN_001d86d0(&v, a4);
    }
    return true;
}
} // namespace fn_001958c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00195a90 FUN_00195a90 (132 B): equivalent/0x00195a90.cpp [wrapped: conflict: hulkfight::motion::ProjectileEffect]
// sym: ??0ProjectileEffect@motion@hulkfight@fn_00195a90@@QAE@PAUOwner_195a90@3@@Z
namespace fn_00195a90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00195a90 @ 0x00195a90
struct Owner_195a90 { char pad[0x18]; char position[0x60]; unsigned int value; };
struct Matrix { char data[64]; void FUN_0022b980(); };
struct Manager_195a90 { unsigned int FUN_00283a40(void*, Matrix*, float, float); };
Manager_195a90* __cdecl FUN_0027f250();
struct FUN_001b6800 { virtual void dummy(); unsigned int a,b,value,d,e; FUN_001b6800(); };
namespace hulkfight { namespace motion {
struct ProjectileEffect : FUN_001b6800 {
 Owner_195a90* owner; unsigned int handle; unsigned int fields[10]; float time; unsigned int last;
 virtual void dummy();
 ProjectileEffect(Owner_195a90*);
};
}}
hulkfight::motion::ProjectileEffect::ProjectileEffect(Owner_195a90* p) {
 owner=0; fields[0]=0; fields[1]=0; fields[2]=0; fields[3]=0; fields[4]=0; fields[5]=0; fields[6]=0; fields[7]=0; fields[8]=0; fields[9]=0; time=-1.0f; last=0;
 owner=p; value=p->value;
 Matrix m; m.FUN_0022b980();
 Manager_195a90* manager=FUN_0027f250();
 handle=manager->FUN_00283a40(owner->position,&m,-1.0f,1.0f);
}
} // namespace fn_00195a90


// 0x00195b20 hulkfight::motion::ProjectileEffect::vfunc_3 (4 B): matches/0x00195b20.cpp
// sym: ?vfunc_3@ProjectileEffect@motion@hulkfight@@UAEPAXXZ
void* hulkfight::motion::ProjectileEffect::vfunc_3() {
    return (void*)((hulkfight::motion::ProjectileEffect*)((char*)this + 0x34));
}


// 0x00195b30 FUN_00195b30 (73 B): matches/0x00195b30.cpp [wrapped: conflict: FUN_0027f250]
// sym: ?Cleanup@ProjectileEffect@fn_00195b30@@QAEXXZ
namespace fn_00195b30 {
extern "C" char DAT_0041b3f4[];
class Base_195b30 {
  public:
    virtual void V0();
    virtual void V1();
};
class Helper_195b30 {
  public:
    void Use_0027ffb0(void*);
};
extern Helper_195b30* FUN_0027f250();
class ProjectileEffect {
  public:
    void* vptr;
    char pad04[0x14];
    void* m18;
    void* m1c;
    char pad20[4];
    Base_195b30* m24;
    void Finish_001b6820();
    void Cleanup();
};
void ProjectileEffect::Cleanup() {
    *(void**)this = (void*)((hulk_intptr)DAT_0041b3f4);
    if (m1c) {
        Helper_195b30* x = FUN_0027f250();
        x->Use_0027ffb0(m1c);
    }
    if (m24) {
        m24->V1();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Finish_001b6820();
}
} // namespace fn_00195b30


// 0x00195bb0 hulkfight::motion::ProjectileEffect::vfunc_4 (1639 B): equivalent/0x00195bb0.cpp [wrapped: conflict: FUN_0027f250; World; hulkfight::motion::ProjectileEffect]
// sym: ?vfunc_4@ProjectileEffect@motion@hulkfight@fn_00195bb0@@UAEXM@Z
namespace fn_00195bb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3047 inputs, branch coverage 58/58)
// hulkfight::motion::ProjectileEffect::vfunc_4 @ 0x00195bb0
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

union FloatBits {
    float f;
    unsigned u;
};
struct Vec3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_0022b980();
    bool FUN_0022d2b0(hulk_uintptr other, float tolerance);
    void FUN_00011160(float distance, hulk_uintptr direction);
};
struct Transform {
    float elements[12];
    Vec3 position;
    void FUN_0022b980();
};
struct ProjectileConfig {
    char pad0[0x20];
    Vec3 forward;
    char pad2c[0x34];
    float targetSpeed;
    float acceleration;
    char pad68[8];
    float traceDistance;
    char pad74[0xc];
    unsigned traceMask;
    char pad84[4];
    float impactScale;
    char pad8c[4];
    Vec3 fallback;
    unsigned hitParam9c;
    char padA0[8];
    unsigned hitParamA8;
    char padAc[8];
    unsigned hitParamB4;
    unsigned hitParamB8;
    int impactCount;
};
struct Releasable {
    virtual void v0();
    virtual void Release();
};
struct Thing {
    unsigned FUN_001d72e0();
};
struct Registry {
    unsigned FUN_00059c10(unsigned id);
};
struct CollisionType {
    unsigned FUN_001d5e80(unsigned value);
};
struct Matrix {
    void FUN_0022c3b0(hulk_uintptr from, hulk_uintptr to);
};
struct VObj {
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
    virtual Matrix* v15();
};
struct Spawn {
    void FUN_0027ffc0(unsigned effect, hulk_uintptr transform);
    void FUN_0027ffb0(unsigned effect);
};
struct ImpactSpawner {
    void FUN_00283a40(hulk_uintptr config, hulk_uintptr transform, unsigned neg, unsigned pos);
};
struct ImpactEvents {
    void FUN_001f6cd0(unsigned effect, unsigned object, hulk_uintptr point, hulk_uintptr normal, hulk_uintptr direction,
                      unsigned count, unsigned a, unsigned b, unsigned c, unsigned d);
};
struct World {
    char pad[0x38];
    ImpactEvents* events;
    char pad3c[8];
    Registry* registry;
};
extern "C" unsigned FUN_00098190(float dt, unsigned speed, unsigned distance, unsigned z1, hulk_uintptr object, unsigned z2,
                      hulk_uintptr position, hulk_uintptr direction, unsigned z3, unsigned z4, unsigned z5,
                      unsigned one);
// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
char FUN_00195290(hulk_uintptr point, hulk_uintptr hitObject, hulk_uintptr effect, hulk_uintptr previous, hulk_uintptr position,
                  hulk_uintptr normal, hulk_uintptr hit, unsigned material, unsigned zero, hulk_uintptr flag,
                  unsigned zero2);
// equiv-conv: FUN_001958c0 eax stack stack stack stack stack stack stack stack stack stack
char FUN_001958c0(unsigned owner, hulk_uintptr hit, unsigned p9c, unsigned pa8, hulk_uintptr point, hulk_uintptr normal,
                  hulk_uintptr direction, unsigned pb8, unsigned pb4, unsigned zero, unsigned mask);
// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
char FUN_00195560(hulk_uintptr direction, hulk_uintptr hit, hulk_uintptr point, unsigned owner, unsigned p9c,
                  unsigned pa8, hulk_uintptr normal, unsigned pb8, unsigned pb4, unsigned zero, unsigned mask,
                  unsigned zero2, unsigned one, unsigned zero3);
unsigned FUN_0027f250();
hulk_freg FUN_000964e0();
extern "C" void FUN_00224db0(hulk_uintptr transform, hulk_uintptr a, hulk_uintptr b);
namespace hulkfight {
namespace motion {
class ProjectileEffect {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(float dt);
    char pad04[8];
    float lifetime;
    unsigned char stopped;
    char pad11[7];
    ProjectileConfig* config;
    unsigned effect;
    unsigned owner;
    Releasable* tracked;
    Vec3 previous;
    Vec3 position;
    Vec3 direction;
    float speed;
};
} // namespace motion
} // namespace hulkfight

void hulkfight::motion::ProjectileEffect::vfunc_4(float dt) {
    FloatBits absolute;
    absolute.f = dt;
    absolute.u &= 0x7fffffff;
    if (stopped || absolute.f <= 1e-5f)
        return;

    lifetime -= dt;
    ProjectileConfig* settings = config;
    float traceDistance = settings->traceDistance;
    if (tracked && traceDistance > 0.0f) {
        if (!FUN_00098190(dt, *(unsigned*)&speed, *(unsigned*)&traceDistance, 0, (hulk_uintptr)tracked, 0,
                          (hulk_uintptr)&position, (hulk_uintptr)&direction, 0, 0, 0, 1)) {
            Releasable* old = tracked;
            if (old)
                old->Release();
            tracked = 0;
        }
    }

    settings = config;
    if (settings->acceleration <= 0.0f) {
        speed = settings->targetSpeed;
    } else {
        volatile float maxChange = settings->acceleration * dt;
        if (speed - settings->targetSpeed < -maxChange)
            speed = maxChange + speed;
        else if (speed - settings->targetSpeed > maxChange)
            speed = speed - maxChange;
        else
            speed = settings->targetSpeed;
    }

    struct Frame {
        unsigned flagWord;
        FloatBits material;
        Vec3 orientation;
        Vec3 normal;
        unsigned hit;
        unsigned object;
        unsigned directionAddress;
        Vec3 point;
        unsigned effect;
        unsigned context;
        Vec3 up;
        Transform transform;
    } frame;
    frame.orientation.x = direction.x;
    frame.orientation.y = direction.y;
    frame.orientation.z = direction.z;
    volatile float currentSpeed = speed;
    frame.orientation.y = frame.orientation.y * currentSpeed;
    frame.orientation.z = frame.orientation.z * currentSpeed;
    position.x = ((frame.orientation.x * currentSpeed) * dt) + position.x;
    position.y = frame.orientation.y * dt + position.y;
    position.z = frame.orientation.z * dt + position.z;

    World* context = DAT_004dd700;
    frame.material.u = 0;
    hulk_uintptr materialObject = context->registry->FUN_00059c10(owner);
    if (materialObject)
        frame.material.u = *(unsigned*)((char*)materialObject + 0x12c);

    frame.hit = 0;
    frame.object = 0;
    frame.directionAddress = (hulk_uintptr)&direction;
    frame.effect = 0;
    frame.context = (hulk_uintptr)context;
    unsigned char* hitFlag = (unsigned char*)&frame.flagWord + 3;
    *hitFlag = FUN_00195290((hulk_uintptr)&frame.point, (hulk_uintptr)&frame.object, (hulk_uintptr)&frame.effect,
                            (hulk_uintptr)&previous, (hulk_uintptr)&position, (hulk_uintptr)&frame.normal,
                            (hulk_uintptr)&frame.hit, frame.material.u, 0, (hulk_uintptr)hitFlag, 0);
    previous.x = position.x;
    previous.y = position.y;
    previous.z = position.z;

    hulk_uintptr collision = frame.hit;
    if (frame.object && *(unsigned*)(frame.object + 0x38) == 5)
        collision = ((Thing*)*(hulk_uintptr*)(frame.object + 0x3c))->FUN_001d72e0();

    if (collision) {
        unsigned collisionKind = *(unsigned*)(collision + 0xc);
        if (collisionKind == 1) {
            settings = config;
            unsigned mask = settings->traceMask;
            unsigned pb4 = settings->hitParamB4;
            unsigned pb8 = settings->hitParamB8;
            unsigned pa8 = settings->hitParamA8;
            unsigned p9c = settings->hitParam9c;
            if (!FUN_00195560((hulk_uintptr)&direction, collision, (hulk_uintptr)&frame.point, owner, p9c, pa8,
                              (hulk_uintptr)&frame.normal, pb8, pb4, 0, mask, 0, 0x3f800000, 0))
                *hitFlag = 0;
        } else if (collisionKind == 5) {
            settings = config;
            unsigned mask = settings->traceMask;
            unsigned pb4 = settings->hitParamB4;
            unsigned pb8 = settings->hitParamB8;
            unsigned pa8 = settings->hitParamA8;
            unsigned p9c = settings->hitParam9c;
            if (!FUN_001958c0(owner, collision, p9c, pa8, (hulk_uintptr)&frame.point, (hulk_uintptr)&frame.normal,
                              (hulk_uintptr)&direction, pb8, pb4, 0, mask)) {
                *hitFlag = 0;
            } else {
                collision = *(unsigned*)(collision + 8);
                if (collision && ((CollisionType*)*(hulk_uintptr*)(collision + 0xec))
                                         ->FUN_001d5e80(*(unsigned*)(collision + 0x40)) == 2) {
                    frame.up.x = 0.0f;
                    frame.up.y = 1.0f;
                    frame.up.z = 0.0f;
                    ((VObj*)collision)->v15()->FUN_0022c3b0((hulk_uintptr)&frame.up, (hulk_uintptr)&frame.normal);

                    if ((frame.normal.z * direction.z + frame.normal.y * direction.y +
                         frame.normal.x * direction.x) > 0.0f) {
                        frame.normal.x = frame.normal.x * -1.0f;
                        frame.normal.y = frame.normal.y * -1.0f;
                        frame.normal.z = frame.normal.z * -1.0f;
                    }
                    volatile float dot = ((-direction.z * frame.normal.z) + (-direction.y * frame.normal.y)) +
                                         (-direction.x * frame.normal.x);
                    frame.orientation.x = frame.normal.x;
                    frame.orientation.y = frame.normal.y;
                    frame.orientation.z = frame.normal.z;
                    volatile float reflectedY = frame.orientation.y * (dot + dot);
                    volatile float reflectedZ = frame.orientation.z * (dot + dot);
                    volatile float reflectedX = frame.orientation.x * (dot + dot) + direction.x;
                    frame.orientation.x = reflectedX;
                    frame.orientation.y = reflectedY + direction.y;
                    frame.orientation.z = reflectedZ + direction.z;
                    frame.orientation.FUN_0022d110();
                    direction.y = frame.orientation.y;
                    direction.x = frame.orientation.x;
                    direction.z = frame.orientation.z;
                    position.y = frame.point.y;
                    position.x = frame.point.x;
                    position.z = frame.point.z;
                    volatile float distance = dt * speed;
                    position.FUN_00011160(distance, (hulk_uintptr)&direction);
                    *hitFlag = 0;
                    hulk_uintptr next = *(unsigned*)(collision + 0x114);
                    if (next && *(unsigned*)(next + 0xc) == 1) {
                        next = *(unsigned*)(next + 8);
                        if (next)
                            owner = **(unsigned**)(next + 0x10);
                    }
                }
            }
        }
    }

    hulk_uintptr spawner = FUN_0027f250();
    if (!*hitFlag) {
        frame.transform.FUN_0022b980();
        frame.orientation.x = config->forward.x;
        frame.orientation.y = config->forward.y;
        frame.orientation.z = config->forward.z;
        frame.orientation.FUN_0022d110();
        if (!direction.FUN_0022d2b0((hulk_uintptr)&frame.orientation, 1e-5f))
            FUN_00224db0((hulk_uintptr)&frame.transform, (hulk_uintptr)&frame.orientation, (hulk_uintptr)&direction);
        frame.transform.position.x = position.x;
        frame.transform.position.y = position.y;
        frame.transform.position.z = position.z;
        ((Spawn*)spawner)->FUN_0027ffc0(effect, (hulk_uintptr)&frame.transform);
        return;
    }

    ((Spawn*)spawner)->FUN_0027ffb0(effect);
    effect = 0;
    frame.transform.FUN_0022b980();
    frame.orientation.x = config->fallback.x;
    frame.orientation.y = config->fallback.y;
    frame.orientation.z = config->fallback.z;
    FloatBits length;
    length.f = frame.orientation.FUN_0022d110();
    length.u &= 0x7fffffff;
    if (length.f <= 1e-5f) {
        frame.orientation.x = FUN_000964e0() + 0.001f;
        frame.orientation.y = FUN_000964e0() + 0.001f;
        frame.orientation.z = FUN_000964e0() + 0.001f;
        frame.orientation.FUN_0022d110();
    }
    if (!frame.orientation.FUN_0022d2b0((hulk_uintptr)&frame.normal, 1e-5f))
        FUN_00224db0((hulk_uintptr)&frame.transform, (hulk_uintptr)&frame.orientation, (hulk_uintptr)&frame.normal);
    frame.transform.position.x = frame.point.x;
    frame.transform.position.y = frame.point.y;
    frame.transform.position.z = frame.point.z;
    ((ImpactSpawner*)spawner)
        ->FUN_00283a40((hulk_uintptr)&config->impactScale, (hulk_uintptr)&frame.transform, 0xbf800000, 0x3f800000);
    lifetime = 0.0f;
    if (frame.effect) {
        int count = ((volatile ProjectileConfig*)config)->impactCount;
        if (count > 0)
            ((World*)frame.context)
                ->events->FUN_001f6cd0(frame.effect, frame.object, (hulk_uintptr)&frame.point,
                                       (hulk_uintptr)&frame.normal, (hulk_uintptr)&direction, count - 1, 0x3f800000,
                                       0x3f800000, 0, 0);
    }
}
} // namespace fn_00195bb0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

