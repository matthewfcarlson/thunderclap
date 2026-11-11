// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0001b080..0x0001cf40 (kind game, layer game, confidence high), dominant class CWeaponCollisionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f260fe7b {
#define TREE_TU_END }
namespace fn_f260fe7b {} using namespace fn_f260fe7b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f260fe7b {
struct RefObj_1b080 {
    virtual void AddRef();
    virtual void Release();
};
struct Owner_1b080 {
    char pad00[0xb8];
    V3i pos;
};
extern "C" char DAT_003f34c8[];
struct CWeaponCollisionAction {
    hulk_intptr vptr;
    char pad04[0x18];
    RefObj_1b080 *f1c;
    Owner_1b080 *owner;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    char pad34[0x40];
    int f74;
    int f78;
    RefObj_1b080 *f7c;

    void FUN_00232660();
    CWeaponCollisionAction *FUN_0001b080(RefObj_1b080 *a, Owner_1b080 *b, RefObj_1b080 *c);
};
extern void* gA_1b120[];
class Ref_1b120 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_1b120 {
  public:
    void* vptr;
};
class CWeaponCollisionAction_1b120 : public CAction_1b120 {
  public:
    char pad_1c[0x18];
    Ref_1b120* m1c;
    char pad_24[0x4];
    Ref_1b120* m24;
    char pad_7c[0x54];
    Ref_1b120* m7c;
    ~CWeaponCollisionAction_1b120();
};
struct Children_1b170 { Node **begin; Node **end; };
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type();
 char pad04[16]; Children_1b170 *children; char pad18[48]; float values[3];
};
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int type(); virtual void v7(); virtual void v8(); virtual void update(); virtual void notify();
 char pad[0x44]; float x,y,z,radius;
};
void __cdecl FUN_0001b170(Object*, Object**, float*, int*);
class Ref_1b4f0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1b4f0 {
    char pad[0x24];

  public:
    Ref_1b4f0* ref;
    void F();
};
struct Vec3_1c430 {
    float x, y, z;
    float FUN_0022d110();
};
struct Sensor_1c430 {
    char pad[4];
};
struct Entity {
    char pad0[0x11c];
    int f11c;
    char pad120[0xc];
    int f12c;
    char pad130[0x3a4 - 0x130];
    Sensor_1c430* sensor;
    char pad3a8[0x20b0 - 0x3a8];
    int blocked;
    char FUN_000360f0();
    int FUN_000390e0(Vec3_1c430* c, Vec3_1c430* aux, float radius, Vec3_1c430* hit);
};
struct EntityList_1c430 {
    char pad0[0xc];
    int count;
    Entity* FUN_00024190(int index);
};
} // namespace fn_f260fe7b
struct World {
    char pad0[0x20];
    EntityList_1c430* entities;
};
namespace fn_f260fe7b {
struct Config_1c430 {
    char pad0[0x18];
    float scale;
};
struct Xform_1c430 {
    void FUN_0022c2b0(Vec3_1c430* in, Vec3_1c430* out);
};
struct Source_1c430 {
    char pad0[0x30];
    Vec3_1c430 pos;
    void FUN_0022c2b0(Vec3_1c430* in, Vec3_1c430* out);
};
struct Anchor_1c430 { char pad[4]; };
Anchor_1c430* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(Anchor_1c430* a);
char __cdecl FUN_00096ce0(Sensor_1c430* s, Vec3_1c430* hit, float* out);
union SelfOrDist {
    Entity* self;
    float dist;
};
class CWeaponCollisionAction_1c430 {
public:
    char pad0[0x1c];
    void* owner;
    Config_1c430* cfg;
    char pad24[0x34 - 0x24];
    Xform_1c430 xf;
    void FUN_0001b510(hulk_intptr a, Vec3_1c430* pos, Vec3_1c430* dir, int kind);
    void FUN_0001c430(Source_1c430* src);
};


// 0x0001b080 FUN_0001b080 (156 B): equivalent/0x0001b080.cpp
// sym: ?FUN_0001b080@CWeaponCollisionAction@fn_f260fe7b@@QAEPAU12@PAURefObj_1b080@2@PAUOwner_1b080@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0001b080 @ 0x0001b080
// FUN_0001b080: CWeaponCollisionAction constructor
CWeaponCollisionAction *CWeaponCollisionAction::FUN_0001b080(RefObj_1b080 *a, Owner_1b080 *b, RefObj_1b080 *c)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_003f3390;
    f1c = 0;
    if (c)
        c->AddRef();
    if (f1c)
        f1c->Release();
    f1c = c;
    owner = b;
    vptr = (hulk_intptr)DAT_003f34c8;
    f24 = 0;
    b28 = 0;
    f2c = 0;
    f30 = 0;
    f7c = 0;
    V3i p = b->pos;
    f74 = p.y;
    f78 = p.z;
    if (a)
        a->AddRef();
    if (f7c)
        f7c->Release();
    f7c = a;
    return this;
}


// 0x0001b120 FUN_0001b120 (80 B): matches/0x0001b120.cpp
// sym: ??1CWeaponCollisionAction_1b120@fn_f260fe7b@@QAE@XZ
CWeaponCollisionAction_1b120::~CWeaponCollisionAction_1b120() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    vptr = gA_1b120;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_1b120 *)this)->FUN_002326a0();
}


// 0x0001b170 FUN_0001b170 (266 B): equivalent/0x0001b170.cpp
// sym: ?FUN_0001b170@fn_f260fe7b@@YAXPAUNode@1@PAPAU21@PAMPAH@Z
// STATUS: equivalent (tools/equiv.py level 3: 242 inputs, branch coverage 20/20)
// FUN_0001b170 @ 0x0001b170
void __cdecl FUN_0001b170(Node *node, Node **best, float *maximum, int *index) {
 if (!node) return;
 int kind=node->type();
 if(kind==5) {
 float values[3]; values[0]=node->values[0]; values[1]=node->values[1]; values[2]=node->values[2];
 for(int i=0;i<3;++i) if(values[i]>*maximum) { *maximum=values[i]; *best=node; *index=i; }
 } else if(kind==2) {
 float value=node->values[2]; if(value>*maximum) { *maximum=value; *best=node; *index=-1; }
 }
 Children_1b170 *children=node->children;
 if(children) for(unsigned i=0; i<(unsigned)(children->end-children->begin); ++i) FUN_0001b170(children->begin[i],best,maximum,index);
}


// 0x0001b280 FUN_0001b280 (277 B): equivalent/0x0001b280.cpp
// sym: ?FUN_0001b280@fn_f260fe7b@@YGXPAUObject@1@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 22/22)
// FUN_0001b280 @ 0x0001b280
void __stdcall FUN_0001b280(Object* source, float factor) {
 struct { float limit; int axis; Object* target; } l; // one frame block: the callee fills it, the original lays it out limit, axis, target
 l.target=0; l.limit=0; l.axis=-1;
 FUN_0001b170(source,&l.target,&l.limit,&l.axis);
 Object* target=l.target; float limit=l.limit; int axis=l.axis;
 if (!target) return;
 int type=target->type();
 if (type==2) {
 double value=(double)factor*target->radius;
 if (value>limit) value=limit;
 target->radius=(float)value;
 target->update();
 } else if(type==5 && axis>=0) {
 if(axis!=0) { double value=(double)factor*target->x; if(value>limit) value=limit; target->x=(float)value; }
 if(axis!=1) { double value=(double)factor*target->y; if(value>limit) value=limit; target->y=(float)value; }
 if(axis!=2) { double value=(double)factor*target->z; if(value>limit) value=limit; target->z=(float)value; }
 target->update();
 }
 source->notify();
}


// 0x0001b4f0 FUN_0001b4f0 (24 B): matches/0x0001b4f0.cpp
// sym: ?F@Obj_1b4f0@fn_f260fe7b@@QAEXXZ
void Obj_1b4f0::F() {
    if (ref) {
        ref->B();
        ref = 0;
    }
}

} // namespace fn_f260fe7b

// 0x0001b510 FUN_0001b510 (3860 B): equivalent/0x0001b510.cpp [wrapped: macros]
// sym: ?FUN_0001b510@SpawnAction@fn_0001b510@@QAEXPAUItem@2@PAUV3@2@1PAX@Z
namespace fn_0001b510 {
// STATUS: equivalent (tools/equiv.py level 3: 3297 inputs, branch coverage 180/187, incomplete)
// FUN_0001b510 @ 0x0001b510
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

typedef unsigned __int64 u64;

struct V3 {
    float x, y, z;
    hulk_freg FUN_000111f0();
    hulk_freg FUN_0022d110();
    void FUN_00011160(float f, V3 *v);
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Request {
    hulk_intptr r00;
    int r04;
    V3 target;                     // 8
    float f14;
    V3 aim;                        // 0x18
    unsigned char flag24;          // 0x24
    char pad25[0x38 - 0x25];
    V3 v38;
    unsigned char b44;
    char pad45[0x4c - 0x45];
    RefObj *f4c;
    RefObj *f50;
    int r54;
    float r58;
    char pad5c[0x68 - 0x5c];
    float r68;
    RefObj *f6c;
    int f70;
    void *f74;
    float f78;
    float f7c;
    float f80;
    char pad84[0x98 - 0x84];
    void FUN_00059820();
    void FUN_000595f0(V3 *v, float a, float b, float c);
    void FUN_00059300();
};

struct Job {
    virtual void v0();
    virtual void v1();
    Job *FUN_000598e0(void *a, Request *req);
};

struct Sink;
struct Handle {
    char FUN_00231ad0(Sink *sink, Job *job, int n);
};
struct Sink {
    int v;
    char FUN_00231e80(Handle *h);
};

struct Queue {
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual Handle *Submit(Job *job, int n);
};

struct Ctrl {
    char pad0[0x10];
    unsigned char b10;
    char pad11[3];
    int f14;
    char pad18[4];
    float f1c;
    char pad20[0x2c - 0x20];
    float f2c;
    char pad30[0x170 - 0x30];
    float f170;
    char pad174[0x1b0 - 0x174];
    int f1b0;
    char pad1b4[0x30c - 0x1b4];
    float f30c;
};

struct Item;
struct Pad;
struct Target;
struct Holder;

struct Player {
    char pad0[0xdc];
    Sink s0dc;
    char pade0[0x11c - 0xe0];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char pad130[0x328 - 0x130];
    int f328;
    char pad32c[0x334 - 0x32c];
    Pad *f334;
    Pad *f338;
    char pad33c[0x390 - 0x33c];
    Pad *f390;
    char pad394[0x1b28 - 0x394];
    int f1b28;
    float FUN_0003ebb0(int a);
    char FUN_00035c30(Item *it);
    void FUN_00035c70(void *it);
    void FUN_00035230(V3 *out);
    void FUN_0003ffa0(void *obj, int zero);
    RefObj *FUN_00035ef0(int a);
    void FUN_00035b70(int a, int b, int c);
    void FUN_0003a9d0(RefObj *o);
};

struct Slot {
    float FUN_001d4e90();
    u64 FUN_001d4f70();
};

struct Aux {
    char pad0[8];
    hulk_intptr f08;
    int f0c;
};

struct Pad {
    char pad0[0x10];
    struct Anchor *f10;
    char pad14[0xdc - 0x14];
    Sink s0dc;
    char pade0[0xec - 0xe0];
    Slot *fec;
    char padf0[0x108 - 0xf0];
    int f108;
    char pad10c[4];
    char b110;
    char pad111[3];
    Aux *f114;
    char pad118[0x11c - 0x118];
    Ctrl *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char pad130[0x140 - 0x130];
    int f140;
    char pad144[0x148 - 0x144];
    hulk_intptr f148;
    char pad14c[0x198 - 0x14c];
    int f198;
    float f19c;
    char pad1a0[0x3a4 - 0x1a0];
    int f3a4;
    char pad3a8[0x20b0 - 0x3a8];
    int f20b0;
    char FUN_000360f0();
    void FUN_000437a0(float v, Request *req, int a, int b, int c);
    void FUN_00035b70(float a, float b, float c);
    void FUN_0003a9d0(RefObj *o);
    void FUN_0003ffa0(void *obj, int zero);
    char FUN_001d6980();
    int FUN_001d64a0();
    void FUN_001d86d0(V3 *a, V3 *b);
    char FUN_001d6ec0(int a, RefObj *b, int c);
    void FUN_0027d4f0(int a);
};

struct Target {
    char pad0[0x64];
    float a;
    float b;
    float c;
    char pad70[0x100 - 0x70];
    void *obj;
    void FUN_00081420(Request *req);
};

struct Item : RefObj {
    int pad4;
    void *f08;
    int f0c;
};

struct Blob {
    char f0;
};

struct Cfg {
    char pad0[0x14];
    int f14;
    char pad18[4];
    int f1c;
    int f20;
    char pad24[4];
    int f28;
    Queue *f2c;
    char pad30[8];
    Queue *f38;
    char pad3c[0x48 - 0x3c];
    RefObj *f48;
    int f4c;
    Blob f50;
    char pad54[0x90 - 0x54];
    float f90;
    float f94;
    char pad98[0xb0 - 0x98];
    int fb0;
    int fb4;
    char padb8[0xc4 - 0xb8];
    int fc4;
    float fc8;
    unsigned char fcc;
    char padcd[3];
    float fd0;
    float fd4;
    float fd8;
    float fdc;
    float fe0;
    unsigned char fe4;
    char pade5[3];
    float fe8;
    float fec;
    float ff0;
    float ff4;
    float ff8;
    void FUN_00012590(V3 *out);
    void FUN_000125c0(V3 *out);
    void FUN_00012610(V3 *out);
};

struct Holder {
    virtual void h0();
    char pad4[0x34 - 4];
    unsigned char b34;
    char pad35[0x4c - 0x35];
    RefObj *f4c;
};

struct Anchor {
    void *f0;
    Player *FUN_00059a30();
    void FUN_00059a50(V3 *out);
};

struct Owner {
    virtual void o0(); virtual void o1(); virtual void o2();
    virtual Holder *o3();
    int f04;
    void *f08;
    Anchor *FUN_000592a0();
};

struct Hud {
    void FUN_001cbd10(const char *s);
};

struct Scale {
    float FUN_001dddf0();
};

struct Runner {
    void FUN_001ecc80(Player *y, Pad *o, RefObj *r, Blob *b);
    void FUN_001ee090(Player *y, Pad *o, RefObj *r, Blob *b);
};

struct JudgeCfg {
    char pad0[0x352];
    unsigned char b352;
};

struct World {
    char pad0[0xc];
    Scale *f0c;
    char pad10[0x20 - 0x10];
    JudgeCfg *f20;
    char pad24[0x30 - 0x24];
    Hud *f30;
    Runner *f34;
};


extern "C" int __cdecl FUN_00266da0(int v);
extern "C" Job *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj **slot, RefObj *obj);
void __cdecl FUN_000187a0(RefObj **slot, RefObj *obj);
void __cdecl FUN_00018840(int *slot, int v);
extern "C" char __cdecl FUN_000444f0(int v);
hulk_freg __cdecl FUN_00224f10(V3 *v);
void __cdecl FUN_00224d70(float f, V3 *v);
hulk_freg __cdecl FUN_000964e0();
float __cdecl FUN_000445a0();
float __cdecl FUN_000445b0();
// equiv-conv: FUN_00014210 eax ecx edx esi
extern "C" void FUN_00014210(int mode, Player *frame, void *obj, V3 *out);


struct Frame {
    union {
        volatile float mult;
        Ctrl *ctrl;
    };                             // E-256
    union {
        float l252;
        Aux *aux;
    };                             // E-252
    float l248;                    // E-248
    int token;                     // E-244
    char pad240[3];
    unsigned char flag;            // E-237
    Player *Y;                     // E-236
    union {
        hulk_intptr l232;
        float f232;
    };                             // E-232
    V3 mid;                        // E-228
    V3 p216;                       // E-216
    V3 p204;                       // E-204
    float l192;                    // E-192
    V3 p188;                       // E-188
    V3 p176;                       // E-176
    Request req;                   // E-164
    V3 out;                        // E-12
};

class SpawnAction {
public:
    char pad00[0x1c];
    Owner *f1c;
    Cfg *f20;
    Item *f24;
    char pad28[4];
    int f2c;
    int f30;
    char pad34[0x74 - 0x34];
    float f74;
    float f78;
    RefObj *f7c;

    void FUN_0001b510(Item *a4, V3 *a8, V3 *a12, void *a16);
};

#define SPAWN(ZQ, B44V)                                                    \
    f.req.FUN_00059820();                                                  \
    f.req.target = *a8;                                                    \
    f.req.aim = *a12;                                                      \
    f.req.f78 = f.l248;                                                    \
    f.req.b44 = (B44V);                                                    \
    Job *job = FUN_0008d690(0xb0);                                         \
    if (job)                                                               \
        job = job->FUN_000598e0(f1c->f08, &f.req);                         \
    job->v0();                                                             \
    Handle *hd = (ZQ)->Submit(job, 0);                                     \
    if (hd) {                                                              \
        if (!f.Y->s0dc.FUN_00231e80(hd))                                    \
            hd->FUN_00231ad0(&f.Y->s0dc, job, -1);                         \
    }                                                                      \
    job->v1();                                                             \
    f.req.FUN_00059300();

void SpawnAction::FUN_0001b510(Item *e, V3 *a8, V3 *a12, void *a16)
{
    Frame f;
    {
        Cfg *c = f20;
        if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20)
            return;
    }
    if (f24 == 0)
        return;
    if (e == 0 || e == f24)
        return;
    f.token = FUN_00266da0(0xd);
    do {
    Player *Y = f1c->FUN_000592a0()->FUN_00059a30();
    f.Y = Y;
    if ((RefObj *)e == Y->f12c || Y->FUN_00035c30(e)) {
        break;
    }
    Y->FUN_00035c70(e);
    f.l232 = (hulk_intptr)DAT_004dd700->f20;
    Pad *O = 0;
    f.flag = 0;
    f.mult = 1.0f;
    if (e->f0c == 1) {
        O = (Pad *)e->f08;
    } else if (e->f0c == 7) {
        Anchor *anchor = f1c->FUN_000592a0();
        Player *fighter = anchor->FUN_00059a30();
        Target *t = (Target *)e->f08;
        if (t != 0) {
            f.p204.x = 0.0f;
            f.p204.y = 0.0f;
            f.p204.z = 0.0f;
            anchor->FUN_00059a50(&f.p204);
            f.p216.x = 0.0f;
            f.p216.y = 0.0f;
            f.p216.z = 0.0f;
            fighter->FUN_00035230(&f.p216);
            f.req.FUN_00059820();
            f.req.target.x = a8->x + t->a;
            f.req.target.y = a8->y + t->b;
            f.req.target.z = a8->z + t->c;
            f.req.target.x = f.req.target.x * 0.5f;
            f.req.target.y = f.req.target.y * 0.5f;
            f.req.target.z = f.req.target.z * 0.5f;
            f.mid = f.req.target;
            f.mid.x = f.mid.x - a8->x;
            f.mid.y = f.mid.y - a8->y;
            f.mid.z = f.mid.z - a8->z;
            if (f.mid.FUN_0022d110() > 1.0f) {
                f.req.target = *a8;
                f.req.target.FUN_00011160(1.0f, &f.mid);
            }
            f.req.aim = *a12;
            Cfg *c = f20;
            f.req.r00 = (hulk_intptr)c->f48;
            f.req.r04 = c->f4c;
            f.req.r54 = c->fb4;
            FUN_00018810(&f.req.f4c, fighter->f12c);
            FUN_00014210(f20->fb0, fighter, t->obj, &f.p188);
            c = f20;
            f.req.flag24 = c->fcc;
            f.req.r58 = c->fd0;
            f.req.r68 = c->fe0;
            f.l192 = c->fd8;
            f.l252 = c->fdc;
            f.f232 = c->fd4;
            if (f.req.r58 < 0.0f)
                f.req.r58 = -(FUN_000964e0() * f.req.r58);
            if (f.req.r68 < 0.0f)
                f.req.r68 = -(FUN_000964e0() * f.req.r68);
            f.req.f78 = 1.0f;
            if (f.l192 <= 0.0f)
                f.l192 = f.req.r58;
            f.req.FUN_000595f0(&f.p188, f.f232, f.l192, f.l252);
            t->FUN_00081420(&f.req);
            if (fighter->f328 == 0)
                fighter->FUN_0003ffa0(t->obj, 0);
            fighter->FUN_00035c70(t->obj);
            f.req.FUN_00059300();
        }
        break;
    } else if (e->f0c == 5) {
        Pad *p = (Pad *)e->f08;
        O = (Pad *)p->f148;
        if (O == 0) {
            f.aux = p->f114;
            if (f.aux != 0 && f.aux->f0c == 1) {
                f.mult = p->fec->FUN_001d4e90();
                if (f.mult > 0.0f && p->b110 == 0)
                    O = (Pad *)f.aux->f08;
                else
                    f.mult = 1.0f;
            }
        }
    }

    {
        // lo and hi live in the (not yet used) l248 / l252 slots
        f.l248 = f20->f90;
        f.l252 = f20->f94;
        float v = f.l248;
        if (f.l252 > 0.0f)
            v = Y->FUN_0003ebb0(1) * (f.l252 - f.l248) + f.l248;
        v = v * f.mult;
        if (Y->f1b28 != 0)
            f.l248 = (Y->f11c->f30c * Y->f11c->f170) * v;
        else
            f.l248 = v * Y->f11c->f30c;
    }

    if (O != 0) {
        if (f20->f28 == 1 || O->f20b0 != 0 || O == Y->f338 || O == Y->f334 || O == Y->f390 || O->FUN_000360f0()) {
            break;
        }
        f.ctrl = O->f11c;
        Cfg *c = f20;
        if (f.ctrl->f14 != 0) {
            int l2 = c->f20;
            int l1 = c->f1c;
            if (l2 > 0 && f30 >= l2) {
                break;
            }
            if (l1 > 0 && f2c >= l1) {
                break;
            }
            f30++;
        } else {
            int l1 = c->f1c;
            if (l1 > 0 && f2c >= l1) {
                break;
            }
        }
        f2c++;
        Blob *b = &f20->f50;
        if (b && b->f0) {
            RefObj *r = Y->FUN_00035ef0(c->f14);
            if (r)
                DAT_004dd700->f34->FUN_001ee090(Y, O, r, &f20->f50);
        }
        Holder *pl = f1c->o3();
        f.req.FUN_00059820();
        FUN_00018810(&f.req.f4c, (pl && pl->b34) ? pl->f4c : Y->f12c);
        FUN_00018810(&f.req.f50, O->f12c);
        FUN_000187a0(&f.req.f6c, f7c);
        FUN_00018840(&f.req.f70, Y->s0dc.v);
        {
            hulk_intptr fc4 = f20->fc4;
            if (fc4 != 0)
                f.req.f74 = (void *)fc4;
            else
                f.req.f74 = a16;
        }
        f.p176 = *a8;
        O->f10->FUN_00059a50(&f.p176);
        if (O->f140 == 1 || O->f140 == 2)
            f.p176.y = f.p176.y + f.ctrl->f2c;
        f.req.target.z = a8->z;
        f.req.target.x = f.p176.x + a8->x;
        f.req.target.x = f.req.target.x * 0.5f;
        f.mid.x = f.req.target.x;
        f.req.target.y = (a8->y + f.p176.y) * 0.5f;
        f.mid.y = f.req.target.y;
        f.req.target.z = (f.p176.z + f.req.target.z) * 0.5f;
        f.mid.z = f.req.target.z;
        f.mid.x = f.mid.x - a8->x;
        f.mid.y = f.mid.y - a8->y;
        f.mid.z = f.mid.z - a8->z;
        if (f.mid.FUN_0022d110() > 1.0f) {
            f.req.target = *a8;
            f.req.target.FUN_00011160(1.0f, &f.mid);
        }
        f.req.aim = *a12;
        f.req.r00 = (hulk_intptr)f20->f48;
        f.req.r04 = f20->f4c;
        f.req.f78 = f.l248;
        f.req.r54 = f20->fb4;
        f.req.f7c = Y->FUN_0003ebb0(1);
        f.req.f80 = 1.0f;
        FUN_00014210(f20->fb0, Y, e, &f.out);
        {
            Cfg *c2 = f20;
            c2->FUN_00012590(&f.p216);
            c2->FUN_000125c0(&f.p204);
            if (f.p204.FUN_000111f0() > 0.0f) {
                f.p188.x = f.p204.x - f.p216.x;
                f.p188.y = f.p204.y - f.p216.y;
                f.p188.z = f.p204.z - f.p216.z;
                f.p216.FUN_00011160(Y->FUN_0003ebb0(1), &f.p188);
            }
        }
        f.l252 = FUN_00224f10(&f.out);
        FUN_00224d70(f.l252, &f.p216);
        f.req.v38 = f.p216;
        {
            int sel = O->f11c->f14;
            Cfg *c3;
            if (FUN_000444f0(sel)) {
                c3 = f20;
                f.req.flag24 = c3->fcc;
                f.req.r58 = c3->fd0;
                f.req.r68 = c3->fe0;
                f.l192 = c3->fd8;
                f.l252 = c3->fd4;
                f.f232 = c3->fdc;
                f.mult = f.ctrl->f1c;
                f.mult = FUN_000445a0() / f.mult;
            } else {
                if (sel == 1) {
                    c3 = f20;
                    f.req.flag24 = c3->fe4;
                    f.req.r58 = c3->fe8;
                    f.req.r68 = c3->ff8;
                    f.l192 = c3->ff0;
                    f.l252 = c3->fec;
                    f.f232 = c3->ff4;
                    f.mult = f.ctrl->f1c;
                } else {
                    f.req.flag24 = 0;
                    f.req.r58 = 0.0f;
                    f.req.r68 = 0.0f;
                    f.l192 = 0.0f;
                    f.l252 = 0.0f;
                    f.f232 = 0.0f;
                    f.mult = f.ctrl->f1c;
                }
                f.mult = FUN_000445b0() / f.mult;
            }
        }
        if (f.req.r58 < 0.0f)
            f.req.r58 = -(FUN_000964e0() * f.req.r58);
        if (f.req.r68 < 0.0f)
            f.req.r68 = -(FUN_000964e0() * f.req.r68);
        if (f.l192 <= 0.0f)
            f.l192 = f.req.r58;
        f.req.FUN_000595f0(&f.out, f.mult * f.l252, f.mult * f.l192, f.mult * f.f232);
        if (O->f3a4 == 0 && f24 != 0)
            O->FUN_0003a9d0(f24);
        {
            Queue *q = f20->f2c;
            Handle *hd = 0;
            if (q) {
                Job *job = FUN_0008d690(0xb0);
                if (job)
                    job = job->FUN_000598e0(O->f10->f0, &f.req);
                job->v0();
                hd = q->Submit(job, 0);
                if (hd)
                    hd->FUN_00231ad0(&O->s0dc, job, -1);
                job->v1();
            }
            if (hd == 0)
                O->FUN_000437a0(f.l248, &f.req, 0, 0, 0);
        }
        f20->FUN_00012610(&f.p188);
        O->FUN_00035b70(f.p188.x, f74, f78);
        f74 = f74 * 0.75f;
        f78 = f78 * 0.75f;
        {
            Queue *q2 = f20->f38;
            if (q2) {
                Job *job = FUN_0008d690(0xb0);
                if (job)
                    job = job->FUN_000598e0(f1c->f08, &f.req);
                job->v0();
                Handle *h2 = q2->Submit(job, 0);
                if (h2) {
                    if (!f.Y->s0dc.FUN_00231e80(h2))
                        h2->FUN_00231ad0(&f.Y->s0dc, job, -1);
                }
                job->v1();
            }
        }
        if (f.Y->f328 == 0)
            f.Y->FUN_0003ffa0(O->f12c, 0);
        f.req.FUN_00059300();
    } else {
        if (e->f0c == 5) {
            Pad *p = (Pad *)e->f08;
            int run = 1;
            if (f20->f28 == 2)
                run = 0;
            else if (((JudgeCfg *)f.l232)->b352 == 0)
                run = 2;
            else if (p->FUN_001d6980())
                run = 0;
            if (run == 0) {
                break;
            }
            if (run == 1) {
                if (p->fec->FUN_001d4f70() == (*(u64*)&DAT_004dc030))
                    DAT_004dd700->f30->FUN_001cbd10("golf_stroke");
                Player *Yp = f.Y;
                int k = Yp->f11c->f1b0;
                if (p->f198 == k)
                    f.l248 = f.l248 * p->f19c;
                if (k == 2)
                    f.l248 = DAT_004dd700->f0c->FUN_001dddf0() * f.l248;
                if (p->FUN_001d6ec0((int)f.l248, Yp->f12c, 0)) {
                    p->FUN_0027d4f0(1);
                    f.flag = 1;
                    if (p->FUN_001d64a0() == 4 || p->FUN_001d64a0() == 3) {
                        Cfg *c4 = f20;
                        int c20 = c4->f20;
                        int c1c = c4->f1c;
                        if (!(c20 > 0 && f30 >= c20) && !(c1c > 0 && f2c >= c1c)) {
                            f30++;
                            f2c++;
                        }
                    } else {
                        int c1c = f20->f1c;
                        if (!(c1c > 0 && f2c >= c1c))
                            f2c++;
                    }
                }
                Cfg *c5 = f20;
                c5->FUN_00012590(&f.p216);
                c5->FUN_000125c0(&f.p204);
                if (f.p204.FUN_000111f0() > 0.0f) {
                    f.p188.x = f.p204.x - f.p216.x;
                    f.p188.y = f.p204.y - f.p216.y;
                    f.p188.z = f.p204.z - f.p216.z;
                    f.p216.FUN_00011160(Yp->FUN_0003ebb0(1), &f.p188);
                }
                if (f.p216.FUN_000111f0() > 0.0f) {
                    FUN_00014210(f20->fb0, Yp, e, &f.out);
                    f.l252 = FUN_00224f10(&f.out);
                    f.p204 = f.p216;
                    FUN_00224d70(f.l252, &f.p204);
                    p->FUN_001d86d0(&f.p204, a8);
                }
                RefObj *r = Yp->FUN_00035ef0(f20->f14);
                if (r != 0 && (Pad *)r != p)
                    DAT_004dd700->f34->FUN_001ecc80(Yp, (Pad *)p, r, &f20->f50);
                Queue *q3 = f20->f38;
                if (q3) {
                    f.req.FUN_00059820();
                    f.req.target = *a8;
                    f.req.aim = *a12;
                    f.req.f78 = f.l248;
                    f.req.b44 = (f.flag == 0);
                    Job *job = FUN_0008d690(0xb0);
                    if (job)
                        job = job->FUN_000598e0(f1c->f08, &f.req);
                    job->v0();
                    Handle *hd = q3->Submit(job, 0);
                    if (hd) {
                        if (!f.Y->s0dc.FUN_00231e80(hd))
                            hd->FUN_00231ad0(&f.Y->s0dc, job, -1);
                    }
                    job->v1();
                    f.req.FUN_00059300();
                }
            }
        }
    }
        if (f2c == 1 && f24->f0c == 5) {
            Pad *p = (Pad *)f24->f08;
            float amount = f20->fc8;
            if (amount < 0.0f)
                amount = f.l248 * 0.5f;
            p->FUN_001d6ec0((int)amount, f.Y->f12c, 1);
        }
    } while (0);
    FUN_00266da0(f.token);
}
} // namespace fn_0001b510
#undef SPAWN
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f260fe7b {

// 0x0001c430 FUN_0001c430 (819 B): equivalent/0x0001c430.cpp
// sym: ?FUN_0001c430@CWeaponCollisionAction_1c430@fn_f260fe7b@@QAEXPAUSource_1c430@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 18597 inputs, branch coverage 32/32)
// FUN_0001c430 @ 0x0001c430
void CWeaponCollisionAction_1c430::FUN_0001c430(Source_1c430* src)
{
    SelfOrDist slot;
    slot.self = FUN_00059a30(FUN_000592a0(owner));
    Vec3_1c430 c = src->pos;
    Vec3_1c430 t;
    Vec3_1c430 aux;
    Vec3_1c430 p;
    Vec3_1c430 q;
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    ((owners::M_22c3b0 *)src)->FUN_0022c3b0((float *)(Vec3_1c430 *)(&t), (float *)(Vec3_1c430 *)(&aux));
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    src->FUN_0022c2b0(&t, &p);
    t.x = 0.0f; t.y = 3.5f; t.z = 0.0f;
    xf.FUN_0022c2b0(&t, &q);
    Vec3_1c430 d;
    d.x = p.x - q.x;
    d.y = p.y - q.y;
    d.z = p.z - q.z;
    d.FUN_0022d110();

    hulk_freg radius = cfg->scale * 0.25f;
    EntityList_1c430* list = DAT_004dd700->entities;
    int count = list->count;
    Vec3_1c430 hit;
    for (int i = 0; i < count; i++) {
        Entity* e = list->FUN_00024190(i);
        if (e != slot.self && e != 0 && e->blocked == 0 && !e->FUN_000360f0() && e->f11c != 0) {
            int r = e->FUN_000390e0(&c, &aux, radius, &hit);
            if (r != 0)
                FUN_0001b510(e->f12c, &hit, &d, r);
        }
    }

    Sensor_1c430* sensor = slot.self->sensor;
    if (sensor == 0)
        return;
    if (!FUN_00096ce0(sensor, &hit, &slot.dist))
        return;
    slot.dist = slot.dist * 0.75f;
    if (!(slot.dist < 1.5f))
        slot.dist = 1.5f;
    // The original keeps s and s*s on the x87 stack unrounded (floats near FLT_MAX overflow if s*s is stored as float).
    double s = slot.dist + radius;
    double s2 = s * s;
    hulk_freg dx = c.x - hit.x;
    hulk_freg dy = c.y - hit.y;
    hulk_freg dz = c.z - hit.z;
    hulk_freg sum1 = dz * dz + dy * dy + dx * dx;
    bool nearC = sum1 <= s2;
    hulk_freg ex = p.x - hit.x;
    hulk_freg ey = p.y - hit.y;
    hulk_freg ez = p.z - hit.z;
    hulk_freg sum2 = ez * ez + ey * ey + ex * ex;
    bool nearP = sum2 <= s2;
    if (!nearC && !nearP)
        return;
    Vec3_1c430* other = nearP ? &p : &c;
    Vec3_1c430 mid;
    mid.x = (hit.x + other->x) * 0.5f;
    mid.y = (hit.y + other->y) * 0.5f;
    mid.z = (hit.z + other->z) * 0.5f;
    FUN_0001b510((hulk_intptr)sensor, &mid, &d, 2);
}

} // namespace fn_f260fe7b

// 0x0001c770 FUN_0001c770 (574 B): equivalent/0x0001c770.cpp [wrapped: conflict: Entity; FUN_000592a0; World]
// sym: ?FUN_0001c770@CWeaponCollisionAction_1c770@fn_0001c770@@QAEXPAUSource_1c770@2@M@Z
namespace fn_0001c770 {
// STATUS: equivalent (tools/equiv.py level 3: 18589 inputs, branch coverage 24/24)
// FUN_0001c770 @ 0x0001c770
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

struct Vec3_1c770 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Sensor_1c770 {
    char pad[4];
};

struct Entity {
    char pad0[0x11c];
    int f11c;
    char pad120[0xc];
    int f12c;
    char pad130[0x3a4 - 0x130];
    Sensor_1c770* sensor;
    char pad3a8[0x20b0 - 0x3a8];
    int blocked;
    char FUN_000360f0();
    int FUN_00038f90(Vec3_1c770* origin, float radius, Vec3_1c770* out);
};

struct EntityList_1c770 {
    char pad0[0xc];
    int count;
    Entity* FUN_00024190(int index);
};

struct World {
    char pad0[0x20];
    EntityList_1c770* entities;
};

struct Config_1c770 {
    char pad0[0x18];
    float scale;
};

struct Source_1c770 {
    char pad0[0x30];
    Vec3_1c770 pos;
};


struct Anchor_1c770 { char pad[4]; };
Anchor_1c770* __fastcall FUN_000592a0(void* owner);
Entity* __fastcall FUN_00059a30(Anchor_1c770* a);
char __cdecl FUN_00096ce0(Sensor_1c770* s, Vec3_1c770* hit, float* out);

union CountOrDist {
    int count;
    float dist;
};

class CWeaponCollisionAction_1c770 {
public:
    char pad0[0x1c];
    void* owner;
    Config_1c770* cfg;
    char pad24[0x64 - 0x24];
    Vec3_1c770 target;
    void FUN_0001b510(hulk_intptr a, Vec3_1c770* pos, Vec3_1c770* dir, int kind);
    void FUN_0001c770(Source_1c770* src, float radius);
};

void CWeaponCollisionAction_1c770::FUN_0001c770(Source_1c770* src, float radius)
{
    Entity* self = FUN_00059a30(FUN_000592a0(owner));

    radius = radius * cfg->scale;
    Vec3_1c770 c = src->pos;
    Vec3_1c770 d;
    d.x = c.x - target.x;
    d.y = c.y - target.y;
    d.z = c.z - target.z;
    d.FUN_0022d110();

    Vec3_1c770 hit;
    EntityList_1c770* list = DAT_004dd700->entities;
    // the original reuses the (dead) first argument slot for the count and the float out value
    CountOrDist* slot = (CountOrDist*)&src;
    slot->count = list->count;
    for (int i = 0; i < slot->count; i++) {
        Entity* e = list->FUN_00024190(i);
        if (e != self && e != 0 && e->blocked == 0 && !e->FUN_000360f0() && e->f11c != 0) {
            int r = e->FUN_00038f90(&c, radius, &hit);
            if (r != 0)
                FUN_0001b510(e->f12c, &hit, &d, r);
        }
    }

    Sensor_1c770* sensor = self->sensor;
    if (sensor == 0)
        return;
    if (!FUN_00096ce0(sensor, &hit, &slot->dist))
        return;
    slot->dist = slot->dist * 0.75f;
    if (!(slot->dist < 1.5f))
        slot->dist = 1.5f;
    float s = slot->dist + radius;
    float dx = c.x - hit.x;
    float dy = c.y - hit.y;
    float dz = c.z - hit.z;
    hulk_freg sum = dz * dz + dy * dy + dx * dx;
    if (!(sum <= s * s))
        return;
    Vec3_1c770 mid;
    mid.x = (hit.x + c.x) * 0.5f;
    mid.y = (hit.y + c.y) * 0.5f;
    mid.z = (hit.z + c.z) * 0.5f;
    FUN_0001b510((hulk_intptr)sensor, &mid, &d, 2);
}
} // namespace fn_0001c770
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0001c9b0 CWeaponCollisionAction::vfunc_8 (1263 B): equivalent/0x0001c9b0.cpp [wrapped: conflict: CWeaponCollisionAction]
// sym: ?vfunc_8@CWeaponCollisionAction@fn_0001c9b0@@UAE_NH@Z
namespace fn_0001c9b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20138 inputs, branch coverage 81/84, incomplete)
// CWeaponCollisionAction::vfunc_8 @ 0x0001c9b0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct V3_1c9b0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat_1c9b0 {
    char pad0[0x30];
    V3_1c9b0 pos;
    float w;
    void FUN_0022b980();
    void FUN_0022c2b0(const V3_1c9b0 *in, V3_1c9b0 *out);
};

struct EntA {
    int FUN_001d64a0();
};

struct SrcEnt {
    char pad0[8];
    EntA *f8;
    int kind;
    Mat_1c9b0 mat;
};

struct Config_1c9b0 {
    char pad0[0x18];
    float scale;
    int f1c;
    int f20;
};

void __cdecl FUN_00224ce0(Mat_1c9b0 *a, Mat_1c9b0 *b, float t, Mat_1c9b0 *out);
float __cdecl FUN_000186f0(float *a, float *b);
char __cdecl FUN_00096ce0(SrcEnt *src, V3_1c9b0 *hit, float *out);

class CWeaponCollisionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(int a1);
    char pad04[0x18];
    void *owner;
    Config_1c9b0 *cfg;
    SrcEnt *src;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    Mat_1c9b0 xf;
    void FUN_0001c430(Mat_1c9b0 *m);
    void FUN_0001c770(Mat_1c9b0 *m, float radius);
};

bool CWeaponCollisionAction::vfunc_8(int a1)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        V3_1c9b0 d0;
        V3_1c9b0 tc;
        V3_1c9b0 q;
        int s30;
        V3_1c9b0 tin;
        V3_1c9b0 pp;
        Mat_1c9b0 M;
        Mat_1c9b0 M2;
    } f;

    if (src == 0)
        return false;
    int type = 0;
    if (src->kind == 5)
        type = src->f8->FUN_001d64a0();

    if (b28) {
        Mat_1c9b0 *sm = &src->mat;
        float r25 = cfg->scale * 0.25f;
        f.tc.x = xf.pos.x;
        f.tc.y = xf.pos.y;
        f.s0 = (float)(r25 + r25);
        f.d0.x = sm->pos.x;
        f.tc.z = xf.pos.z;
        f.d0.x = f.d0.x - f.tc.x;
        f.d0.y = sm->pos.y;
        f.d0.z = sm->pos.z;
        f.d0.y = f.d0.y - f.tc.y;
        f.tin.x = 0.0f;
        f.d0.z = f.d0.z - f.tc.z;
        f.tin.y = 3.5f;
        f.tin.z = 0.0f;
        sm->FUN_0022c2b0(&f.tin, &f.pp);
        xf.FUN_0022c2b0(&f.tin, &f.q);
        double ex = f.pp.x - f.q.x;
        double ey = f.pp.y - f.q.y;
        double ez = f.pp.z - f.q.z;
        f.s4 = (float)sqrt(ez * ez + ey * ey + ex * ex);
        double len2 = sqrt((double)f.d0.z * f.d0.z + (double)f.d0.y * f.d0.y + (double)f.d0.x * f.d0.x);
        double maxd = len2;
        if (f.s4 > len2)
            maxd = f.s4;
        if (maxd < f.s0) {
            FUN_0001c430(sm);
        } else {
            double n = maxd / f.s0;
            int cnt = (int)(__int64)n;
            if ((double)(n - (double)cnt) > 0.0)
                cnt++;
            if (cnt > 0x40)
                cnt = 0x40;
            int last = cnt - 1;
            bool done = false;
            if (last > 0) {
                f.s0 = (float)cnt;
                int i = 0;
                do {
                    int next = i + 1;
                    f.s4 = (float)next;
                    FUN_00224ce0(&xf, sm, (float)((double)f.s4 / f.s0), &f.M);
                    FUN_0001c430(&f.M);
                    Config_1c9b0 *c = cfg;
                    if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20) {
                        done = true;
                        break;
                    }
                    i = next;
                } while (i < last);
            }
            if (!done) {
                Config_1c9b0 *c = cfg;
                if (!(c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20))
                    FUN_0001c430(sm);
            }
        }
        memcpy(&xf, sm, sizeof(Mat_1c9b0));
    } else if (type != 0) {
        SrcEnt *s = src;
        f.s8 = 1.0f;
        char ok = FUN_00096ce0(s, &f.q, &f.s8);
        if (ok) {
            f.M.FUN_0022b980();
            f.s8 = f.s8 * 0.75f;
            f.M.pos = f.q;
        } else {
            memcpy(&f.M, &src->mat, sizeof(Mat_1c9b0));
            f.s8 = 1.0f;
        }
        int ebp = type;
        float m;
        if (ebp == 3 || ebp == 4) {
            if (f.s8 < 1.5f)
                m = f.s8;
            else
                m = 1.5f;
            if (f.s8 < 1.5f && m < 0.25f)
                m = 0.25f;
        } else {
            f.s0 = FUN_000186f0(&f.s8, ((float*)&DAT_003f2ecc));
            if (f.s0 < 0.25f)
                f.s0 = 0.25f;
            m = f.s0;
        }
        f.d0 = xf.pos;
        f.tc = f.M.pos;
        double dx2 = f.tc.x - f.d0.x;
        double dy2 = f.tc.y - f.d0.y;
        double dz2 = f.tc.z - f.d0.z;
        double len = sqrt(dz2 * dz2 + dy2 * dy2 + dx2 * dx2);
        double m2 = m + m;
        if (len < m2) {
            FUN_0001c770(&f.M, m);
        } else {
            double r = len / m2;
            int cnt = (int)(__int64)r;
            if ((double)(r - (double)cnt) > 0.0)
                cnt++;
            if (cnt > 0x40)
                cnt = 0x40;
            f.s4 = (float)cnt;
            int last = cnt - 1;
            f.s30 = last;
            bool done = false;
            if (last > 0) {
                f.s0 = (float)cnt;
                int i = 0;
                do {
                    int next = i + 1;
                    f.s4 = (float)next;
                    FUN_00224ce0(&xf, &f.M, (float)((double)f.s4 / f.s0), &f.M2);
                    FUN_0001c770(&f.M2, m);
                    Config_1c9b0 *c = cfg;
                    if (c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20) {
                        done = true;
                        break;
                    }
                    i = next;
                } while (i < last);
            }
            if (!done) {
                Config_1c9b0 *c = cfg;
                if (!(c->f1c > 0 && f2c >= c->f1c && c->f20 > 0 && f30 >= c->f20))
                    FUN_0001c770(&f.M, m);
            }
        }
        memcpy(&xf, &f.M, sizeof(Mat_1c9b0));
    }

    Config_1c9b0 *ce = cfg;
    bool reached = ce->f1c > 0 && f2c >= ce->f1c && ce->f20 > 0 && f30 >= ce->f20;
    return !reached;
}
} // namespace fn_0001c9b0


// 0x0001cea0 CWeaponCollisionAction::vfunc_4 (153 B): matches/0x0001cea0.cpp [wrapped: conflict: CWeaponCollisionAction; FUN_000592a0]
// sym: ?vfunc_4@CWeaponCollisionAction@fn_0001cea0@@UAEXXZ
namespace fn_0001cea0 {
// CWeaponCollisionAction::vfunc_4 @ 0x0001cea0
void *__fastcall FUN_000592a0(void *owner);

struct Fx_1cea0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetScale(float s);
};
struct Attach_1cea0 { char pad[0x20]; Fx_1cea0 *fx; };
struct Target_1cea0 { void FUN_001d7330(int a); };
struct Thing_1cea0 {
    virtual void v0();
    virtual void Release();
    char pad04[4];
    Target_1cea0 *target;
    int kind;
    char pad10[0x74 - 0x10];
    Attach_1cea0 *attach;
};
struct RefObj_1cea0 {
    virtual void v0();
    virtual void Release();
};
struct Weapon_1cea0 { char pad[0x24]; char active; };
struct Hero_1cea0 {
    char pad0[0x1b49];
    char flag;
    char pad1b4a[0x1e48 - 0x1b4a];
    int f1e48;
    bool FUN_00035ab0();
    void FUN_0003b580(int a, int b, int c);
};
Hero_1cea0 *__fastcall FUN_00059a30(void *x);

class CWeaponCollisionAction {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4();
    char pad04[0x18];
    void *owner;
    Weapon_1cea0 *weapon;
    Thing_1cea0 *thing;
    char pad28[0x7c - 0x28];
    RefObj_1cea0 *extra;
};

void CWeaponCollisionAction::vfunc_4()
{
    Hero_1cea0 *hero = FUN_00059a30(FUN_000592a0(owner));
    if (weapon->active && hero->FUN_00035ab0())
        hero->FUN_0003b580(0, 0, 0);
    hero->flag = 0;
    if (thing != 0) {
        hero->f1e48 = 0;
        if (thing->attach != 0) {
            Fx_1cea0 *fx = thing->attach->fx;
            if (fx != 0)
                fx->SetScale(1.0f);
        }
        if (thing->kind == 5)
            thing->target->FUN_001d7330(0);
        if (thing != 0) {
            thing->Release();
            thing = 0;
        }
        if (extra != 0) {
            extra->Release();
            extra = 0;
        }
    }
}
} // namespace fn_0001cea0

