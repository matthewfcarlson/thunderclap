// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0004a990..0x0004adc0 (kind game, layer game, confidence medium), dominant class CClimbEdgeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f87d197d {
#define TREE_TU_END }
namespace fn_f87d197d {} using namespace fn_f87d197d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f87d197d {
extern int* gTable_4a990;
class CCondition_4a990 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f87d197d

// 0x0004a990 CClimbEdgeCondition::vfunc_0 (16 B): matches/0x0004a990.cpp
// sym: ?vfunc_0@CClimbEdgeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CClimbEdgeCondition::vfunc_0(int index) {
    int* p = gTable_4a990;
    return p[index];
}


// 0x0004a9d0 CClimbEdgeCondition::vfunc_7 (977 B): equivalent/0x0004a9d0.cpp [wrapped: conflict: CClimbEdgeCondition]
// sym: ?vfunc_7@CClimbEdgeCondition@fn_0004a9d0@@UAE_NPAUParams@2@@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0004a9d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 42/42)
// CClimbEdgeCondition::vfunc_7 @ 0x0004a9d0
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

struct Vec3_4a9d0 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float scale, Vec3_4a9d0 *dir);
    void FUN_000111b0(Vec3_4a9d0 *a, Vec3_4a9d0 *b);
};

struct HitExtra_4a9d0 {
    int b;
    int c;
    int d;
    int e;
};

struct HitInfo_4a9d0 {
    char pad00[0x16];
    unsigned char flags16;
};

struct Limits_4a9d0 {
    char pad00[0x30];
    float half;
    float full;
};

struct Fighter_4a9d0 {
    char pad00[0x11c];
    Limits_4a9d0 *limits;
    char pad120[0x334 - 0x120];
    void *attach334;
    void *attach338;
    char pad33c[0x1af8 - 0x33c];
    Vec3_4a9d0 facing;
    unsigned int contact;
    char FUN_00038de0(Vec3_4a9d0 *from, Vec3_4a9d0 *to, int a, int foreign, HitExtra_4a9d0 *outB, Vec3_4a9d0 *outN, int c, HitInfo_4a9d0 **hit);
};

struct Owner_4a9d0 {
    Fighter_4a9d0 *FUN_00059a30();
    char FUN_00059a50(Vec3_4a9d0 *out);
};

struct Params {
    Owner_4a9d0 *FUN_000592a0();
};

struct Holder_4a9d0 {
    char pad00[0x124];
    void *current;
};

struct World {
    char pad00[0x20];
    Holder_4a9d0 *holder;
};


class CClimbEdgeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Params *params);
    char pad04[8];
    int type;
    char checkSweep;
};

bool CClimbEdgeCondition::vfunc_7(Params *params)
{
    if (type < 0 || type >= 6) {
        return false;
    }
    Owner_4a9d0 *owner = params->FUN_000592a0();
    Fighter_4a9d0 *f = owner->FUN_00059a30();
    unsigned int contact = f->contact;
    if (type == 4) {
        return (contact & 0xf) == 0xf;
    }
    if (type == 5) {
        return contact == 0;
    }
    if (!(contact & (1 << type))) {
        return false;
    }
    if (!checkSweep) {
        return true;
    }
    Limits_4a9d0 *lim = f->limits;
    if (lim == 0) {
        return false;
    }
    float h = lim->half;
    float m = lim->full;
    Vec3_4a9d0 v = f->facing;
    v.y = 0.0f;
    v.FUN_0022d110();

    Vec3_4a9d0 d;
    Vec3_4a9d0 w;
    switch (type) {
    case 0:
        d.y = 1.0f;
        d.x = 0.0f;
        d.z = 0.0f;
        h = h * 0.5f;
        break;
    case 3:
        d.y = -1.0f;
        d.x = 0.0f;
        d.z = 0.0f;
        h = h * 0.5f;
        break;
    case 1:
        w.y = 1.0f;
        w.x = 0.0f;
        w.z = 0.0f;
        d.FUN_000111b0(&w, &v);
        h = m;
        break;
    case 2:
        w.y = -1.0f;
        w.x = 0.0f;
        w.z = 0.0f;
        d.FUN_000111b0(&w, &v);
        h = m;
        break;
    default:
        return false;
    }

    Vec3_4a9d0 nv;
    nv.x = v.x * -1.0f;
    nv.y = v.y * -1.0f;
    nv.z = v.z * -1.0f;
    Vec3_4a9d0 pos;
    if (!owner->FUN_00059a50(&pos)) {
        return false;
    }
    pos.FUN_00011160(m, &v);

    float twoH = h + h;
    Vec3_4a9d0 e;
    e.x = pos.x + d.x * twoH;
    e.y = pos.y + d.y * twoH;
    e.z = pos.z + d.z * twoH;

    int foreign = 0;
    void *cur = DAT_004dd700->holder->current;
    if (f != cur && f->attach338 != cur && f->attach334 != cur) {
        foreign = 1;
    }
    Vec3_4a9d0 hitN;
    HitExtra_4a9d0 hitB;
    HitInfo_4a9d0 *hit;
    if (f->FUN_00038de0(&pos, &e, 0, foreign, &hitB, &hitN, 0, 0)) {
        return false;
    }
    float twoM = m + m;
    Vec3_4a9d0 p;
    p.x = nv.x * twoM + e.x;
    p.y = nv.y * twoM + e.y;
    p.z = nv.z * twoM + e.z;
    if (f->FUN_00038de0(&e, &p, 0, foreign, &hitB, &hitN, 0, 0)) {
        return false;
    }
    float back = h * -2.0f;
    e = p;
    p.x = d.x * back + e.x;
    p.y = d.y * back + e.y;
    p.z = d.z * back + e.z;
    hit = 0;
    if (!f->FUN_00038de0(&e, &p, 0, foreign, &hitB, &hitN, 0, &hit)) {
        return false;
    }
    if (hit != 0 && (hit->flags16 & 0x10)) {
        return false;
    }
    return !(hitN.x * d.x + (hitN.y * d.y + hitN.z * d.z) < 0.8f);
}
} // namespace fn_0004a9d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

