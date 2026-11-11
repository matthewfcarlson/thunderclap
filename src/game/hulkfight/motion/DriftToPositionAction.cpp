// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00174fb0..0x001755e0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::DriftToPositionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f735d51c {
#define TREE_TU_END }
namespace fn_f735d51c {} using namespace fn_f735d51c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f735d51c {
struct Ref_174fb0 {
    virtual void f();
    virtual void g();
};
struct Sub_174fb0 {
    void Init_0027af00();
    char d[8];
};
class Action_174fb0 {
  public:
    Action_174fb0();
    virtual void v0();
    char pad[0x18];
};
class DriftToPositionAction_174fb0 : public Action_174fb0 {
  public:
    int a;
    Ref_174fb0* r;
    char flag24;
    char p25[3];
    char p28[0xc];
    int f34;
    Sub_174fb0 sub;
    int f40;
    int f44;
    int f48;
    int f4c;
    char f50;
    char f51;
    char f52;
    DriftToPositionAction_174fb0(int x, Ref_174fb0* p);
    virtual void v0();
};
extern void* hulk_at_00417ed8[];
class Ref_175020 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_175020 {
  public:
    void* vptr;
};
void Free(void*) throw();
struct Sub_175020 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_175020*) throw();
void __fastcall SubFini2(Sub_175020*) throw();
class DriftToPositionAction_175020 : public Action_175020 {
  public:
    char p1c[24];
    void* m1c;
    Ref_175020* m20;
    char p38[20];
    Sub_175020 s38;
    ~DriftToPositionAction_175020() throw();
};


// 0x00174fb0 FUN_00174fb0 (104 B): matches/0x00174fb0.cpp
// sym: ??0DriftToPositionAction_174fb0@fn_f735d51c@@QAE@HPAURef_174fb0@1@@Z
DriftToPositionAction_174fb0::DriftToPositionAction_174fb0(int x, Ref_174fb0* p) {
    a = 0;
    r = 0;
    flag24 = 1;
    f34 = 0;
    sub.Init_0027af00();
    f50 = 0;
    f51 = 0;
    f4c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f52 = 0;
    a = x;
    if (p)
        p->f();
    if (r)
        r->g();
    r = p;
}


// 0x00175020 FUN_00175020 (58 B): matches/0x00175020.cpp
// sym: ??1DriftToPositionAction_175020@fn_f735d51c@@QAE@XZ
DriftToPositionAction_175020::~DriftToPositionAction_175020() throw() {
    vptr = hulk_at_00417ed8;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    FUN_0027af50(&s38);
    ((fight::Action *)(Action_175020 *)this)->FUN_002326a0();
}

} // namespace fn_f735d51c

// 0x00175060 hulkfight::motion::DriftToPositionAction::vfunc_3 (761 B): equivalent/0x00175060.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_3@DriftToPositionAction@motion@hulkfight@fn_00175060@@UAE_NHM@Z @40192628bb96 @w173791c6cde7
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00175060 {
// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 38/42, incomplete)
// hulkfight::motion::DriftToPositionAction::vfunc_3 @ 0x00175060
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


struct Vec3_175060 {
    float x, y, z;
    hulk_freg FUN_00018990();
};

struct Id_175060 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *name);
};

struct Transform_175060 {
    void FUN_00059a50(Vec3_175060 *out);
};

struct Selector_175060 {
    int FUN_001034d0();
};

struct Marker_175060 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float v7();
    char pad04[0x10];
    unsigned char flag14;
    char pad15[3];
    Vec3_175060 origin;
    char pad24[4];
    const char *name;
};

struct Handle_175060 {
    Selector_175060 *FUN_000fdc40();
};

struct Actor_175060 {
    char pad0[0x10];
    Transform_175060 *transform;
    char pad14[0x1ca0 - 0x14];
    Handle_175060 *handle;
    char pad1ca4[0x1cf4 - 0x1ca4];
    unsigned char b1cf4;
    char pad1cf5[0x2140 - 0x1cf5];
    unsigned char b2140;
    void FUN_00035ce0(int v);
    void FUN_00035460(Vec3_175060 *pos);
    void FUN_00035400(Vec3_175060 *pos);
    int FUN_00036d30();
};

struct Body_175060 {
    Actor_175060 *FUN_00059a30();
};

struct Owner_175060 {
    Body_175060 *FUN_000592a0();
};

struct Path_175060 {
    char pad0[0x14];
    int count;
    Vec3_175060 *FUN_00106160(int index);
};

struct Registry_175060 {
    char pad0[0x18];
    Path_175060 *FUN_00106230(int key);
};

struct World {
    char pad0[0x18];
    Registry_175060 *registry;
};


static bool IdIs(const Id_175060 &id, __int64 v)
{
    return (((__int64)id.hi << 32) | id.lo) == v;
}

namespace hulkfight {
namespace motion {

class DriftToPositionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, float b);
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad04[0x18];
    Marker_175060 *marker;         // 0x1c
    Owner_175060 *owner;           // 0x20
    unsigned char copyFlag; // 0x24
    char pad25[3];
    Vec3_175060 snapshot;          // 0x28
    float timer;            // 0x34
    Id_175060 id;                  // 0x38
    Vec3_175060 pos;               // 0x40
    int bestIndex;          // 0x4c
    unsigned char saved50;  // 0x50
    unsigned char saved51;  // 0x51
    unsigned char moved;    // 0x52
};

}
}

bool hulkfight::motion::DriftToPositionAction::vfunc_3(int a, float b)
{
    Vec3_175060 A;
    Vec3_175060 B;
    float best;
    Vec3_175060 *first;

    Body_175060 *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor_175060 *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;

    float t = marker->v7();
    timer = t;
    if (t <= 0.0f)
        return false;

    moved = 0;
    saved51 = actor->b2140;
    actor->b2140 = 1;
    Marker_175060 *m = marker;
    bestIndex = 0;
    copyFlag = m->flag14;
    float ox = m->origin.x;
    float oy = m->origin.y;
    float oz = m->origin.z;
    snapshot.x = ox;
    A.x = ox;
    snapshot.y = oy;
    snapshot.z = oz;
    A.y = oy;
    A.z = oz;
    id.FUN_0027b040(marker->name);
    saved50 = actor->b1cf4;
    actor->FUN_00035ce0(1);

    if (IdIs(id, DAT_004e13d0)) {
        actor->FUN_00035460(&pos);
        actor->transform->FUN_00059a50(&A);
        pos.x = A.x;
        pos.z = A.z;
        pos.x = snapshot.x + pos.x;
        pos.y = snapshot.y + pos.y;
        pos.z = snapshot.z + pos.z;
        moved = 1;
    }
    if (IdIs(id, DAT_004e13e0)) {
        actor->FUN_00035400(&pos);
        pos.x = snapshot.x + pos.x;
        pos.y = snapshot.y + pos.y;
        pos.z = snapshot.z + pos.z;
        moved = 1;
    }
    if (IdIs(id, DAT_004e13c0)) {
        Registry_175060 *reg = DAT_004dd700->registry;
        Path_175060 *path = reg->FUN_00106230(actor->FUN_00036d30());
        if (path == 0) {
            if (actor->handle == 0)
                return false;
            if (actor->handle->FUN_000fdc40() == 0)
                return false;
            Selector_175060 *sel = actor->handle->FUN_000fdc40();
            reg = DAT_004dd700->registry;
            path = reg->FUN_00106230(sel->FUN_001034d0());
            if (path == 0)
                return false;
        }
        first = path->FUN_00106160(bestIndex);
        if (first == 0)
            return false;
        B = *first;
        actor->transform->FUN_00059a50(&A);
        B.x = B.x - A.x;
        B.y = B.y - A.y;
        B.z = B.z - A.z;
        best = B.FUN_00018990();
        int count = path->count;
        for (int i = 1; count > i; i++) {
            Vec3_175060 *p = path->FUN_00106160(i);
            B.z = p->z;
            double dy = p->y - A.y;
            B.x = p->x - A.x;
            double dz = B.z - A.z;
            double d = sqrt(dz * dz + dy * dy + B.x * B.x);
            if (d < best && d > 0.01) {
                best = (float)d;
                bestIndex = i;
            }
        }
        if (bestIndex != 0) {
            first = path->FUN_00106160(bestIndex);
            if (first == 0)
                return false;
        }
        if (first) {
            pos.x = first->x;
            pos.y = first->y;
            pos.z = first->z;
        }
        moved = 1;
    }
    return true;
}
} // namespace fn_00175060
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00175360 hulkfight::motion::DriftToPositionAction::vfunc_5 (629 B): equivalent/0x00175360.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@DriftToPositionAction@motion@hulkfight@fn_00175360@@UAE_NHM@Z @712b1afc4d37 @wa35a5478324b
namespace fn_00175360 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 44/44)
// hulkfight::motion::DriftToPositionAction::vfunc_5 @ 0x00175360

struct Vec3_175360 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
    bool FUN_0022d2b0(const Vec3_175360 *other, float eps);
};

struct Flagged_175360 {
    char pad00[0x24];
    bool flag;
};

struct Actor_175360 {
    char pad000[0x2064];
    Vec3_175360 direction;
    float strength;
    void FUN_000353a0(Vec3_175360 *v);
    void FUN_00035720(Vec3_175360 *v);
    void FUN_000354e0(float v);
};

struct Body_175360 {
    Actor_175360 *FUN_00059a30();
    void FUN_00059a50(Vec3_175360 *out);
};

struct Owner_175360 {
    Body_175360 *FUN_000592a0();
};

extern "C" hulk_freg FUN_00224f10(Vec3_175360 *v);

static bool IdIs(int lo, int hi, __int64 v)
{
    return (((__int64)hi << 32) | (unsigned int)lo) == v;
}

namespace hulkfight {
namespace motion {

class DriftToPositionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    Flagged_175360 *marker;        // 0x1c
    Owner_175360 *owner;           // 0x20
    bool useSnapshot;       // 0x24
    char pad25[3];
    Vec3_175360 snapshot;          // 0x28
    float timer;            // 0x34
    int idLo;               // 0x38
    int idHi;               // 0x3c
    Vec3_175360 pos;               // 0x40
    char pad4c[6];
    bool moved;             // 0x52
};

}
}

bool hulkfight::motion::DriftToPositionAction::vfunc_5(int mode, float dt)
{
    struct Frame {
        Vec3_175360 e;
        Vec3_175360 d;
        Vec3_175360 v;
    } fr;

    if (mode != 0 || dt == 0.0f)
        return true;

    Body_175360 *body = owner->FUN_000592a0();
    if (body == 0)
        return false;
    Actor_175360 *actor = body->FUN_00059a30();
    if (actor == 0)
        return false;
    body->FUN_00059a50(&fr.v);

    if (IdIs(idLo, idHi, DAT_004e13d0) || IdIs(idLo, idHi, DAT_004e13e0)) {
        if (!(DAT_004e13f4 & 1))
            DAT_004e13f4 |= 1;
        (*(Vec3_175360*)&DAT_004e13e8).z = 0;
        (*(Vec3_175360*)&DAT_004e13e8).y = 0;
        (*(Vec3_175360*)&DAT_004e13e8).x = 0;
        if (pos.FUN_0022d2b0(((Vec3_175360*)&DAT_004e13e8), 1e-5f))
            return false;
    }

    if (useSnapshot) {
        pos = snapshot;
        moved = true;
    } else if ((idLo == 0 && idHi == 0) || IdIs(idLo, idHi, DAT_004e13c8)) {
        actor->FUN_000353a0(&pos);
        moved = true;
    }

    fr.d.x = pos.x - fr.v.x;
    fr.d.y = pos.y - fr.v.y;
    fr.d.z = pos.z - fr.v.z;
    if ((idLo == 0 && idHi == 0) || IdIs(idLo, idHi, DAT_004e13c8)) {
        if (marker->flag)
            fr.d.y = 0;
    }
    float len = fr.d.FUN_00018990();
    float m = (timer > dt ? dt / timer : 1.0f) * len;
    fr.e = fr.d;
    fr.e.FUN_0022d110();
    fr.e.x = fr.e.x * m;
    fr.e.y = fr.e.y * m;
    fr.e.z = fr.e.z * m;
    actor->FUN_00035720(&fr.e);
    actor->direction = fr.e;
    actor->direction.FUN_0022d110();
    actor->strength = 1.0f;
    if (IdIs(idLo, idHi, DAT_004e13e0))
        actor->FUN_000354e0(FUN_00224f10(&fr.e));
    timer = timer - dt;
    return !(timer <= 0.0f);
}
} // namespace fn_00175360

