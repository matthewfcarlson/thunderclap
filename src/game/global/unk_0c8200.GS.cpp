// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c8200..0x000c96e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2af3f62 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2af3f62 {} using namespace fn_f2af3f62;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2af3f62 {
struct Vec3 { float x, y, z; };
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Key {
    unsigned int lo, hi;
    Key *FUN_0027b0e0(const char *name);
    void FUN_0027af50();
};
struct Id64 {
    unsigned int lo, hi;
    void FUN_0027af70(unsigned int *src);
};
struct Markers {
    char pad0[0xc];
};
struct Mgr {
    int FUN_001dd330(Key *b, Key *a, Matrix *m, int p0, int p1, int p2, int p3);
    void FUN_001dc2d0(int id, int a0);
    void FUN_001dc230(int id, int mode);
};
} // namespace fn_f2af3f62
struct World {
    char pad0[0xc];
    Mgr *mgr;
};
namespace fn_f2af3f62 {
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
struct MarkerSlot {
    int f00;
    float f04, f08, f0c;
    Id64 f10;
    float f18, f1c, f20, f24, f28, f2c;
    int f30;
    int f34;
};
class Obj_c8200 {
public:
    char pad0[0x2258];
    MarkerSlot slots[32];
    int FUN_000c8200(int a0, unsigned int *a1, float a2, float a3, float a4,
                     float a5, float a6, float a7, float a8, float a9, float a10);
};


// 0x000c8200 FUN_000c8200 (521 B): equivalent/0x000c8200.cpp
// sym: ?FUN_000c8200@Obj_c8200@fn_f2af3f62@@QAEHHPAIMMMMMMMMM@Z @02d4457f3d6d @w2b07b6451976
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// FUN_000c8200 @ 0x000c8200
int Obj_c8200::FUN_000c8200(int a0, unsigned int *a1, float a2, float a3, float a4,
                            float a5, float a6, float a7, float a8, float a9, float a10)
{
    struct Frame {
        Vec3 tmp;
        Key keyB;
        Key keyA;
        Matrix m;
        char name[0x40];
    } f;
    int r = -1;
    int i;
    for (i = 0; i < 32; i++) {
        if (slots[i].f00 != 0)
            continue;
        MarkerSlot *s = &slots[i];
        FUN_000964a0(f.name, 0x40, "%s_%d_%d", "markerObjective_markerObjective", -1, i);
        f.tmp.x = a5 + a2;
        f.tmp.y = a6 + a3;
        f.tmp.z = a7 + a4;
        f.m.FUN_0022b980();
        ((owners::Target_22be40 *)&(f.m))->FUN_0022be40((const int *)(const Vec3 *)(&f.tmp));
        ((owners::Matrix_22bc20 *)&(f.m))->FUN_0022bc20(a8 * 0.0174532924f, a9 * 0.0174532924f, a10 * 0.0174532924f);
        Mgr *mgr = DAT_004dd700->mgr;
        s->f30 = mgr->FUN_001dd330(f.keyB.FUN_0027b0e0(f.name),
                                   f.keyA.FUN_0027b0e0("markerObjective_markerObjective"),
                                   &f.m, 0, 0, 0, 0);
        f.keyB.FUN_0027af50();
        f.keyA.FUN_0027af50();
        if (s->f30 == -1)
            break;
        mgr->FUN_001dc2d0(s->f30, a0);
        mgr->FUN_001dc230(s->f30, 3);
        s->f00 = a0;
        s->f10.FUN_0027af70(a1);
        s->f04 = a2;
        s->f08 = a3;
        s->f0c = a4;
        s->f18 = a5;
        s->f1c = a6;
        s->f20 = a7;
        s->f24 = a8;
        s->f28 = a9;
        s->f2c = a10;
        s->f34 = -1;
        r = i;
        break;
    }
    return r;
}

} // namespace fn_f2af3f62

// 0x000c9550 FUN_000c9550 (381 B): equivalent/0x000c9550.cpp [wrapped: conflict: World]
// sym: ?FUN_000c9550@fn_000c9550@@YGXPBDPAUTarget_c9550@1@H@Z @a59d82e60e34 @w3a65b8244bca
namespace fn_000c9550 {
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 14/14)
// FUN_000c9550 @ 0x000c9550
// cl-flags: /GS
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
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
#endif


class Handle_c9550 {
public:
    virtual void v0();
    virtual void Release();
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22();
    virtual bool v23();
    bool FUN_00266750();
    int FUN_00266700();
};

struct Request {
    char name[0x100];
    int f100;
    int f104;
    int f108;
    char f10c;
    char pad10d[3];
};

struct Mgr_c9550 {
    char pad00[4];
    int limit;
    void FUN_00265810(Request* r, Handle_c9550** out);
    int FUN_00264870();
};

struct Item_c9550 {
};

struct Scene_c9550 {
    Item_c9550* FUN_000862e0();
};

struct World {
    char pad00[0x54];
    Scene_c9550* scene;
};

struct Target_c9550 {
    void FUN_00266220(int v);
};

void thunk_FUN_00271230(Handle_c9550** out, const char* name, int a, int b, int c, int d, int e, int f);
void FUN_002656a0();

void __stdcall FUN_000c9550(const char* name, Target_c9550* target, int arg)
{
    struct Frame {
        Handle_c9550* l2;
        Handle_c9550* l1;
        Request req;
    } f;
    thunk_FUN_00271230(&f.l1, name, 0, 0, 1, 0, 1, 1);
    if (!f.l1->v23()) {
        if (f.l1)
            f.l1->Release();
        return;
    }
    if (f.l1) {
        f.l1->Release();
        f.l1 = 0;
    }
    f.l2 = 0;
    f.req.name[0] = 0;
    f.req.f100 = 0;
    f.req.f104 = 0;
    f.req.f108 = 0;
    f.req.f10c = 0;
    if (name)
        strncpy(f.req.name, name, 0xff);
    f.req.f108 = arg;
    f.req.f10c = 0;
    (*(Mgr_c9550**)&DAT_00527c58)->FUN_00265810(&f.req, &f.l2);
    int saved = (*(Mgr_c9550**)&DAT_00527c58)->FUN_00264870();
    ((owners::C_264860 *)((*(Mgr_c9550**)&DAT_00527c58)))->FUN_00264860(250000);
    Scene_c9550* scene = DAT_004dd700->scene;
    while (!f.l2->FUN_00266750()) {
        FUN_002656a0();
        ((owners::Thing_1eb2a0 *)(scene->FUN_000862e0()))->FUN_001eb2a0(0, 0);
    }
    ((owners::C_264860 *)((*(Mgr_c9550**)&DAT_00527c58)))->FUN_00264860(saved);
    target->FUN_00266220(f.l2->FUN_00266700());
    if (f.l2)
        f.l2->Release();
}
} // namespace fn_000c9550
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

