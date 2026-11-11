// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00109ba0..0x0010ab60 (kind game, layer game, confidence high), dominant class CAvoidBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f710b797 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f710b797 {} using namespace fn_f710b797;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f710b797 {
extern void* hulk_at_0040d770[];
class CAvoidBehaviour_109ba0 {
  public:
    void* vptr;
    void* m4;
    void* m8;
    char mc;
    char p[3];
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    float m28;
    void* m2c;
    void* m30;
    char m34;
    CAvoidBehaviour_109ba0() throw();
};
class CSteeringBehaviour_109be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSteeringBehaviour_109be0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
struct V3_109c00 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
class Ctx_109c00;
class Prober {
public:
    char FUN_00024540(Ctx_109c00 *who);
};
struct Target_109c00 {
    char pad0[0x20];
    Prober *prober;
};
class Ctx_109c00 {
public:
    char pad0[0x1d04];
    char hit;
    char pad1d05[0x2064 - 0x1d05];
    V3_109c00 p2064;
    float limit;
    V3_109c00 p2074;
    char pad2080[0x208c - 0x2080];
    V3_109c00 p208c;
    hulk_freg FUN_00035700();
};
struct Frame_109c00 {
    char pad0[3];
    char flag;
    V3_109c00 diff;
    V3_109c00 w;
    int pad2c;
    volatile float e;
    volatile float f;
    volatile float g;
    int pad3c[4];
    volatile float c;
};
class CAvoidBehaviour {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(Target_109c00 *tgt, Ctx_109c00 *ctx, V3_109c00 *out, int a5, int zero);
    virtual bool vfunc_4(V3_109c00 *a, V3_109c00 *b, Ctx_109c00 *ctx, Target_109c00 *tgt, int a5, V3_109c00 *d, V3_109c00 *c);

    char pad4[0xc];
    V3_109c00 dir;
    V3_109c00 pad1c;
    float peak;
    float ratio;
    int f30;
    char f34;
};
struct Vec3_109df0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(Vec3_109df0* other, float eps);
};
struct Body_109df0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_109df0* GetPosition();   // slot 4
};
struct Node {
    char pad00[8];
    struct Shape_109df0* shape;    // 0x08
    int kind;               // 0x0c
};
struct Shape_109df0 {
    bool FUN_001d6980();
};
struct Entity {
    char pad00[0x18];
    Node* node;             // 0x18
};
struct SweepEntry_109df0 {
    float t;                // 0x00
    Entity* entity;         // 0x04
    Body_109df0* body;             // 0x08
};
struct SweepList_109df0 {
    int count;              // 0x00
    char pad04[4];
    SweepEntry_109df0* entries;    // 0x08
};
struct HitLink {
};
struct Hit_109df0 {
    char pad00[0x38];
    int kind;               // 0x38
    HitLink* link;          // 0x3c
};
struct Sweeper_109df0 {
    bool FUN_002ee140(SweepList_109df0* list, Vec3_109df0* from, Vec3_109df0* to, int flags);
};
struct Space_109df0 {
    bool FUN_00201e00(Vec3_109df0* from, Vec3_109df0* to, int mode, Vec3_109df0* outPoint, Vec3_109df0* outNormal,
                      void** outOther, Hit_109df0** outHit);
};
} // namespace fn_f710b797
struct World {
    char pad00[8];
    Sweeper_109df0* sweeper;       // 0x08
    char pad0c[0x4f4 - 0xc];
    Space_109df0* space;           // 0x4f4
};
namespace fn_f710b797 {
struct Context {
    char pad00[0x10];
    World* world;           // 0x10
};
extern "C" SweepList_109df0* FUN_00202f00();
struct HitOut {
    Hit_109df0* hit;
    void* other;
};


// 0x00109ba0 FUN_00109ba0 (55 B): matches/0x00109ba0.cpp
// sym: ??0CAvoidBehaviour_109ba0@fn_f710b797@@QAE@XZ
CAvoidBehaviour_109ba0::CAvoidBehaviour_109ba0() throw() {
    m4 = 0;
    m8 = 0;
    mc = 0;
    vptr = hulk_at_0040d770;
    *(float*)&m28 = 1.0f;
    m2c = 0;
    m18 = 0;
    m14 = 0;
    m10 = 0;
    m24 = 0;
    m20 = 0;
    m1c = 0;
    m34 = 1;
    m30 = 0;
}


// 0x00109be0 CAvoidBehaviour::vfunc_2 (31 B): matches/0x00109be0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f710b797@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00109c00 CAvoidBehaviour::vfunc_4 (483 B): equivalent/0x00109c00.cpp
// sym: ?vfunc_4@CAvoidBehaviour@fn_f710b797@@UAE_NPAUV3_109c00@2@0PAVCtx_109c00@2@PAUTarget_109c00@2@H00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 12/12)
// CAvoidBehaviour::vfunc_4 @ 0x00109c00
bool CAvoidBehaviour::vfunc_4(V3_109c00 *a, V3_109c00 *b, Ctx_109c00 *ctx, Target_109c00 *tgt, int a5, V3_109c00 *d, V3_109c00 *c)
{
    Frame_109c00 fr;
    fr.flag = 0;
    fr.diff.x = a->x - b->x;
    fr.diff.y = a->y - b->y;
    fr.diff.z = a->z - b->z;
    dir.x = fr.diff.x;
    dir.y = fr.diff.y;
    dir.z = fr.diff.z;
    fr.diff.FUN_0022d110();

    bool hit = false;
    if (tgt && tgt->prober && tgt->prober->FUN_00024540(ctx)) {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
        pad1c.x = 0.0f;
        pad1c.y = 0.0f;
        pad1c.z = 0.0f;
        f34 = 1;
        f30 = 0;
    } else if (v3(tgt, ctx, &fr.w, a5, 0)) {
        hit = true;
        fr.flag = 1;
        fr.c = c->z * 0.1f;
        fr.e = d->y * 0.9f;
        fr.f = d->z * 0.9f;
        fr.g = d->x * 0.9f + c->x * 0.1f;
        double h = fr.e + c->y * 0.1f;
        double i = fr.f + fr.c;
        d->x = fr.g;
        d->y = (float)h;
        d->z = (float)i;
        fr.diff.x = fr.w.x + fr.g;
        fr.diff.y = (float)(fr.w.y + h);
        fr.diff.z = (float)(fr.w.z + i);
        fr.diff.FUN_0022d110();
        ctx->limit = ratio;
    } else {
        // x87: the speed (FUN_00035700's st0) and the quotient stay unrounded; only peak and ratio are stored
        hulk_freg r = ctx->FUN_00035700();
        if (r > peak)
            peak = r;
        hulk_freg q = r / peak;
        if (q > ctx->limit)
            q = ctx->limit;
        ratio = q;
    }
    ctx->hit = hit;
    ctx->p2074.z = fr.diff.z;
    ctx->p2074.x = fr.diff.x;
    ctx->p2074.y = fr.diff.y;
    ctx->p2064.z = fr.diff.z;
    ctx->p2064.x = fr.diff.x;
    ctx->p2064.y = fr.diff.y;
    ctx->p208c.z = fr.w.z;
    ctx->p208c.x = fr.w.x;
    ctx->p208c.y = fr.w.y;
    return fr.flag != 0;
}


// 0x00109df0 FUN_00109df0 (579 B): equivalent/0x00109df0.cpp
// sym: ?FUN_00109df0@fn_f710b797@@YG_NPAUContext@1@PAUVec3_109df0@1@1H111PAUEntity@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 1183 inputs, branch coverage 34/34)
// FUN_00109df0 @ 0x00109df0
bool __stdcall FUN_00109df0(Context* ctx, Vec3_109df0* from, Vec3_109df0* to, int tag, Vec3_109df0* outPoint,
                            Vec3_109df0* outNormal, Vec3_109df0* dir, Entity* ignore)
{
    dir->FUN_0022d110();
    if (from->FUN_0022d2b0(to, 1e-5f))
        return true;

    DAT_004d2a3c = 2;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = tag;

    World* world = ctx->world;
    Sweeper_109df0* sweeper = world->sweeper;
    SweepList_109df0* list = FUN_00202f00();

    if (sweeper->FUN_002ee140(list, from, to, 0)) {
        for (int i = 0; i < list->count; i++) {
            SweepEntry_109df0* e = &list->entries[i];
            if (e->entity) {
                Node* n = e->entity->node;
                if (ignore == 0 || ignore != (Entity*)n) {
                    if (n && n->kind == 5 && !n->shape->FUN_001d6980()) {
                        // swept into a blocker: report the contact and stop
                        float ty = e->t * dir->y;
                        float tz = e->t * dir->z;
                        outPoint->x = (float)(e->t * dir->x + from->x);
                        outPoint->y = ty + from->y;
                        outPoint->z = tz + from->z;
                        Vec3_109df0* p = e->body->GetPosition();
                        dir->x = p->x;
                        dir->y = p->y;
                        dir->z = p->z;
                        dir->y = from->y;
                        dir->x = dir->x - from->x;
                        dir->y = dir->y - from->y;
                        dir->z = dir->z - from->z;
                        Vec3_109df0* q = e->body->GetPosition();
                        float nx = outPoint->x - q->x;
                        float nz = outPoint->z - q->z;
                        outNormal->y = 0;
                        outNormal->x = nx;
                        outNormal->z = nz;
                        outNormal->FUN_0022d110();
                        return false;
                    }
                }
            }
        }
    }

    HitOut out;
    out.hit = 0;
    out.other = 0;
    if (!world->space->FUN_00201e00(from, to, 1, outPoint, outNormal, &out.other, &out.hit))
        return true;

    union { float f; unsigned int u; } ay;
    ay.f = outNormal->y;
    ay.u &= 0x7fffffff;
    if (!(ay.f <= 0.5f))
        return true;
    if (!(outNormal->z * dir->z + dir->y * outNormal->y + outNormal->x * dir->x < 0.0f))
        return true;

    if (out.hit && out.hit->kind == 5 && out.hit->link && ((int)((owners::C_1d72e0 *)(out.hit->link))->FUN_001d72e0()) == (hulk_intptr)ignore)
        return true;
    return false;
}

} // namespace fn_f710b797

// 0x0010a040 CAvoidBehaviour::vfunc_3 (2639 B): equivalent/0x0010a040.cpp [wrapped: conflict: CAvoidBehaviour; World]
// sym: ?vfunc_3@CAvoidBehaviour@fn_0010a040@@UAEDPAUOwner_10a040@2@PAUStats_10a040@2@PAUV3_10a040@2@MD@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0010a040 {
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 83/84, incomplete)
// CAvoidBehaviour::vfunc_3 @ 0x0010a040
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

struct V3_10a040 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
    hulk_freg FUN_000111f0();
    char FUN_0022d2b0(const V3_10a040 *other, float eps);
    void FUN_000344b0(float s);
};

struct Rng_10a040 {
    hulk_freg FUN_00078780();
};
extern "C" Rng_10a040 *__cdecl FUN_000964d0();

struct Pos_10a040 {
    void FUN_00059a50(V3_10a040 *out);
};

struct Ent1fc {
    V3_10a040 *FUN_001fc150(V3_10a040 *a, V3_10a040 *b, V3_10a040 *c);
};
struct Sub58_10a040 {
    Ent1fc *FUN_000fde20(V3_10a040 *out);
};
struct Sub1ca0 {
    char pad00[0x58];
    Sub58_10a040 f58;
};

struct Node1 {
    char pad00[0x10];
    Pos_10a040 *f10;
    void FUN_000368d0(int a);
};

struct Ent74 {
    char pad00[0x72];
    char b72;
};
struct Ent128 {
    char pad00[0x74];
    Ent74 *f74;
};
struct Fighter128_10a040 {
    Ent128 *FUN_001d72e0();
};

struct Stats_10a040 {
    char pad00[0x10];
    Pos_10a040 *f10;
    char pad14[0x128 - 0x14];
    Fighter128_10a040 *f128;
    char pad12c[0x328 - 0x12c];
    int f328;
    char pad32c[0x1ca0 - 0x32c];
    char *f1ca0;
    char pad1ca4[0x1cf8 - 0x1ca4];
    float f1cf8;
    float f1cfc;
    float f1d00;
    void FUN_00035550(V3_10a040 *out);
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
};


struct Owner20_10a040 {
    char pad00[0x124];
    Node1 *f124;
    void FUN_00025260(int a, int b, int c);
    void FUN_000253c0(int a);
};
struct Owner_10a040 {
    char pad00[0x20];
    Owner20_10a040 *f20;
};

struct WorldC {
    void FUN_001dcf60(int a);
};
struct World {
    char pad00[0xc];
    WorldC *fc;
};

extern "C" V3_10a040 *__cdecl FUN_00083e00(V3_10a040 *out, V3_10a040 *dir, float t);
extern "C" float __cdecl FUN_00018710(float *a, float *b);
void __cdecl FUN_00224d70(float angle, V3_10a040 *axis);

struct Frame_10a040 {
    char pad0[3];
    char flagA;             // 3
    float f4;
    float f8;
    char pad12[3];
    char flag2;             // 15
    V3_10a040 v16;
    V3_10a040 P;                   // 28
    V3_10a040 v40;
    V3_10a040 v52;
    V3_10a040 v64;
    float A;                // 76
    float M;                // 80
    float f84;
    V3_10a040 v88;
    V3_10a040 v100;
    float f112;
    char pad116[3];
    char b119;
    V3_10a040 v120;
    V3_10a040 v132;
    V3_10a040 v144;
    V3_10a040 v156;
    V3_10a040 v168;
    V3_10a040 v180;
    V3_10a040 v192;
    V3_10a040 v204;
    V3_10a040 v216;
    V3_10a040 v228;
};

class CAvoidBehaviour {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(Owner_10a040 *owner, Stats_10a040 *st, V3_10a040 *out, float dt, char flag);
    virtual void vfunc_4();
    char pad04[0x10 - 4];
    V3_10a040 v10;
    V3_10a040 v1c;
    char pad28[4];
    float f2c;
    float f30;
    char b34;
    char pad35[3];
    char FUN_00109df0(Owner_10a040 *o, V3_10a040 *p, V3_10a040 *q, float a, V3_10a040 *r, V3_10a040 *s, V3_10a040 *t, int u);
};


char CAvoidBehaviour::vfunc_3(Owner_10a040 *owner, Stats_10a040 *st, V3_10a040 *out, float dt, char flag)
{
    Frame_10a040 f;
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (st == 0)
        return false;
    f.A = st->f1cf8;
    float B = st->f1cfc;
    float C = st->f1d00;
    f.f8 = f.A * 4.0f;
    f.f84 = f.f8;
    if (!(B > f2c))
        B = f2c;
    float R = B * C;
    if (R < f.f8)
        f.M = f.f8;
    else
        f.M = R;
    if (f.A <= 0.0f)
        return false;
    if (f.M <= 0.0f)
        return false;
    f.f8 = v10.FUN_0022d110();
    if (f.f8 == 0.0f)
        return false;
    f.flagA = 0;
    if (f2c > 0.1f) {
        st->FUN_00035550(&f.v40);
        if (f.v40.z * v10.z + f.v40.y * v10.y + f.v40.x * v10.x < 0.99f)
            f.flagA = 1;
        else
            f.flagA = 0;
    } else {
        f.v40.x = v10.x;
        f.v40.z = v10.z;
    }
    f.v40.y = 0;
    if (f.v40.FUN_0022d110() == 0.0f)
        return false;
    f30 = f30 - dt;
    if (f30 > 0.0f && !flag && (!f.flagA || b34)) {
        *out = v1c;
        return b34;
    }
    st->f10->FUN_00059a50(&f.P);
    Owner_10a040 *ow = owner;
    Node1 *nd = ow->f20->f124;
    if (nd) {
        nd->f10->FUN_00059a50(&f.v192);
        f.f4 = f.v192.y - f.P.y;
        unsigned int bits = *(unsigned int *)&f.f4 & 0x7fffffff;
        *(unsigned int *)&f.f4 = bits;
        if (f.f4 >= 1.0f)
            ow->f20->f124->FUN_000368d0(0);
    }
    f.P.y = f.P.y + 0.5f;
    f.flag2 = 0;
    if (st->f1ca0) {
        Sub58_10a040 *s58 = (Sub58_10a040 *)(st->f1ca0 + 0x58);
        if (s58) {
            Ent1fc *e = s58->FUN_000fde20(&f.v16);
            if (e) {
                V3_10a040 *r = e->FUN_001fc150(&f.v204, &f.v16, &f.P);
                f.v40.x = r->x;
                f.v40.y = r->y;
                f.v40.z = r->z;
                f.v40.y = 0;
                f.v40.FUN_0022d110();
                out->x = f.v40.x;
                out->y = f.v40.y;
                out->z = f.v40.z;
                f.flag2 = 1;
            }
        }
    }
    ow->f20->FUN_00025260(1, 0, 0);
    ow->f20->FUN_000253c0(1);
    DAT_004dd700->fc->FUN_001dcf60(1);
    st->FUN_00035fa0(0);
    Fighter128_10a040 *f128 = st->f128;
    if (f128) {
        if (f128->FUN_001d72e0()) {
            Ent128 *e128 = f128->FUN_001d72e0();
            if (e128->f74)
                e128->f74->b72 = 0;
        }
    }
    st->FUN_000368d0(0);

    FUN_00083e00(&f.v88, &f.v40, f.M);
    f.v16.x = f.v88.x + f.P.x;
    f.v100.x = f.v88.x;
    f.v100.y = f.v88.y;
    f.v100.z = f.v88.z;
    f.v16.y = f.v88.y + f.P.y;
    f.v16.z = f.v88.z + f.P.z;
    char r1 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v120, &f.v168, &f.v100, st->f328);
    f.b119 = !r1;
    char bl = 0;
    bool success = false;
    if (!r1) {
        success = true;
    } else if (f.flagA) {
        V3_10a040 *r = FUN_00083e00(&f.v204, &v10, st->f1d00);
        f.v88.x = r->x;
        f.v88.y = r->y;
        f.v88.z = r->z;
        f.v16.x = f.v88.x + f.P.x;
        f.v100.z = r->z;
        f.v16.y = f.v88.y + f.P.y;
        f.v100.x = r->x;
        f.v100.y = r->y;
        f.v16.z = f.v88.z + f.P.z;
        char r2 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v120, &f.v168, &f.v100, st->f328);
        bl = !r2;
        success = (bl != 0);
    }
    if (!success) {
        st->FUN_000368d0(1);
        st->FUN_00035fa0(1);
        Rng_10a040 *rng = FUN_000964d0();
        f30 = (rng->FUN_00078780() * 0.5f + 1.0f) * ((float*)&DAT_004a1eac)[0];
        b34 = f.flag2;
        v1c = *out;
        return f.flag2;
    }

    f.v16.x = f.v120.x - f.P.x;
    f.v16.y = f.v120.y - f.P.y;
    f.v16.z = f.v120.z - f.P.z;
    f.f4 = f.v16.FUN_00018990();
    if (bl || f.f4 > f.f8) {
        *out = f.v40;
        v1c = *out;
        if (!bl)
            f2c = f.f8 / f.f4;
        st->FUN_000368d0(1);
        st->FUN_00035fa0(1);
        Rng_10a040 *rng = FUN_000964d0();
        f30 = (rng->FUN_00078780() * 0.5f + 1.0f) * ((float*)&DAT_004a1eac)[1];
        b34 = 1;
        return true;
    }

    f.f112 = f.f4 / f.M;
    f.f8 = 0.1f;
    f2c = FUN_00018710(&f.f112, &f.f8);
    f.v52 = f.v40;
    f.v64 = f.v40;
    f.f8 = (1.0f - f2c) * 0.785398185f + 0.261799395f;
    FUN_00224d70(-f.f8, &f.v64);
    FUN_00224d70(f.f8, &f.v52);
    f.f112 = f.M * 0.5f;
    f.f84 = FUN_00018710(&f.f112, &f.f84);
    f.v64.FUN_000344b0(f.f84);
    f.v52.FUN_000344b0(f.f84);
    f.v16.x = f.v64.x + f.P.x;
    f.v180 = f.v52;
    f.v16.y = f.v64.y + f.P.y;
    f.v156 = f.v64;
    f.v16.z = f.v64.z + f.P.z;
    char p1 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v132, &f.v216, &f.v156, st->f328);
    f.v16.x = f.v52.x + f.P.x;
    f.v16.y = f.v52.y + f.P.y;
    f.v16.z = f.v52.z + f.P.z;
    char p2 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v144, &f.v228, &f.v180, st->f328);
    bl = !p1;
    f.flagA = !p2;
    st->FUN_000368d0(1);
    st->FUN_00035fa0(1);
    if (ow->f20->f124)
        ow->f20->f124->FUN_000368d0(1);
    int idx = 1;
    if (bl)
        idx = 2;
    if (f.flagA)
        idx++;
    Rng_10a040 *rng2 = FUN_000964d0();
    f30 = (rng2->FUN_00078780() * 0.5f + 1.0f) * ((float*)&DAT_004a1eac)[idx];
    if (bl) {
        if (!f.flagA) {
            *out = f.v52;
        } else {
            f.v16.x = f.v120.x - f.P.x;
            f.v16.y = f.v120.y - f.P.y;
            f.v16.z = f.v120.z - f.P.z;
            f.f8 = f.v16.FUN_000111f0();
            f.v16.x = f.v132.x - f.P.x;
            f.v16.y = f.v132.y - f.P.y;
            f.v16.z = f.v132.z - f.P.z;
            f.f4 = f.v16.FUN_000111f0();
            f.v16.x = f.v144.x - f.P.x;
            f.v16.y = f.v144.y - f.P.y;
            f.v16.z = f.v144.z - f.P.z;
            float d3 = f.v16.FUN_000111f0();
            if (f.f8 > f.f4 && f.f8 > d3 && b34)
                *out = v1c;
            else if (f.f4 > d3)
                *out = f.v64;
            else
                *out = f.v52;
        }
    } else if (f.flagA) {
        *out = f.v64;
    } else {
        if (st->f1d00 * 0.5f > f.f4)
            f.f4 = f.v100.z * f.v40.x - f.v100.x * f.v40.z;
        else
            f.f4 = f.v100.z * v10.x - f.v100.x * v10.z;
        if (f.f4 != 0.0f && !f.v100.FUN_0022d2b0(&f.v88, 1e-05f)) {
            if (f.f4 > 0.0f)
                *out = f.v52;
            else
                *out = f.v64;
        } else {
            if (f.v168.z * f.v40.x - f.v168.x * f.v40.z > 0.0f)
                *out = f.v64;
            else
                *out = f.v52;
        }
    }
    out->FUN_0022d110();
    v1c = *out;
    b34 = 1;
    return true;
}
} // namespace fn_0010a040
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0010aa90 FUN_0010aa90 (200 B): matches/0x0010aa90.cpp [wrapped: conflict: World]
// sym: ?run@Target_10aa90@fn_0010aa90@@QAEEPAUInput_10aa90@2@HHHHHHPAUObject@2@HHH@Z
namespace fn_0010aa90 {
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

struct State_10aa90 {
};
struct Input_10aa90 {
    char pad[0x20];
    State_10aa90* state;
};
struct Flag_10aa90 {
    char pad[0x72];
    unsigned char enabled;
};
struct Node {
    char pad[0x74];
    Flag_10aa90* flag;
};
struct Link_10aa90 {
};
struct Object {
    char pad[0x128];
    Link_10aa90* link;
    void FUN_000368d0(int);
};
struct Manager_10aa90 {
    void FUN_001dcf60(int);
};
struct World {
    char pad[0xc];
    Manager_10aa90* manager;
};
struct Target_10aa90 {
    unsigned char FUN_00109df0(Input_10aa90*, int, int, int, int, int, int, int);
    unsigned char run(Input_10aa90*, int, int, int, int, int, int, Object*, int, int, int);
};
unsigned char Target_10aa90::run(Input_10aa90* input, int a2, int a3, int a4, int a5, int a6, int a7, Object* obj, int a9,
                          int a10, int a11) {
    ((owners::C_25260 *)(input->state))->FUN_00025260(a10, 0, 0);
    ((owners::Target_253c0 *)(input->state))->FUN_000253c0(a11);
    DAT_004dd700->manager->FUN_001dcf60(a11);
    Link_10aa90* link = obj->link;
    if (link && ((Node *)((owners::C_1d72e0 *)link)->FUN_001d72e0())) {
        Node* node = ((Node *)((owners::C_1d72e0 *)link)->FUN_001d72e0());
        Flag_10aa90* flag = node->flag;
        if (flag)
            flag->enabled = 0;
    }
    obj->FUN_000368d0(0);
    unsigned char result = FUN_00109df0(input, a2, a3, a4, a5, a6, a7, a9);
    ((owners::C_25260 *)(input->state))->FUN_00025260(1, 0, 0);
    ((owners::Target_253c0 *)(input->state))->FUN_000253c0(1);
    DAT_004dd700->manager->FUN_001dcf60(1);
    return result;
}
} // namespace fn_0010aa90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

