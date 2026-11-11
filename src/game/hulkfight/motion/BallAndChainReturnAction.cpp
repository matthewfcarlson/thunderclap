// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001825f0..0x00182f10 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainReturnAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe353baa {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe353baa {} using namespace fn_fe353baa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fe353baa {
class A_1825f0 {
  public:
    char pad[0x14];
    int x;
};
class Mid_1825f0 {
  public:
};
class Obj_1825f0 {
  public:
    Mid_1825f0* val();
};
class First_1825f0 {
  public:
};
class Entity {
  public:
    void trigger();
};
class Sink_1825f0 {
  public:
    char pad[0x20];
    void* ptr;
    void send(int);
};
extern Sink_1825f0* gSink;
class End_1825f0 {
  public:
    void finish(int);
};
extern End_1825f0* __stdcall getEnd();
class BallAndChainShootAction_1825f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad[0x18];
    A_1825f0* a;
    First_1825f0* first;
    char rest[0x2c];
    int ending;
};
struct Vec_182660 { float x,y,z; Vec_182660* FUN_0022c2b0(Vec_182660*, Vec_182660*); hulk_freg FUN_0022d110(); };
struct Transform_182660 { Vec_182660* FUN_00221c40(); };
struct TransformHolder { char pad[16]; Transform_182660 transform; };
struct Item_182660 { Vec_182660* FUN_001d6b40(); };
struct Lookup_182660 { Item_182660* FUN_00035ef0(unsigned); };
struct Actor_182660 { Lookup_182660* FUN_00059a30(); TransformHolder* FUN_00059a40(); };
struct Source_182660 { Actor_182660* FUN_000592a0(); };
struct Settings_182660 { char pad[20]; unsigned key; unsigned value; char pad2[16]; Vec_182660 position; };
namespace hulkfight { namespace motion {
struct BallAndChainReturnAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
char pad[24]; Settings_182660* settings; Source_182660* source; Vec_182660 origin; Vec_182660 direction; unsigned value; float length;
};
} }
struct Helper_182c90 {
    Helper_182c90* f59a30();
    void f27ffb0(int);
};
extern Helper_182c90* __cdecl f27f250();
class BallAndChainReturnAction_182c90 {
  public:
    char pad[0x48];
    void vfunc_4();
};


// 0x001825f0 hulkfight::motion::BallAndChainShootAction::vfunc_4 (98 B): matches/0x001825f0.cpp
// sym: ?vfunc_4@BallAndChainShootAction_1825f0@fn_fe353baa@@UAEXXZ
void BallAndChainShootAction_1825f0::vfunc_4() {
    First_1825f0* f = first;
    Obj_1825f0* o = ((Obj_1825f0 *)((owners::Object_592a0 *)f)->FUN_000592a0());
    Mid_1825f0* m = o->val();
    int x = a->x;
    Entity* e = (Entity*)((void *)((owners::C_35ef0 *)m)->FUN_00035ef0((hulk_intptr)x));
    if (e) {
        e->trigger();
        Sink_1825f0* root = gSink;
        if (root) {
            Sink_1825f0* s = (Sink_1825f0*)root->ptr;
            if (s)
                s->send(((int)((owners::C_1d72e0 *)e)->FUN_001d72e0()));
        }
    }
    End_1825f0* end = getEnd();
    end->finish(ending);
}


// 0x00182660 hulkfight::motion::BallAndChainReturnAction::vfunc_3 (222 B): equivalent/0x00182660.cpp
// sym: ?vfunc_3@BallAndChainReturnAction@motion@hulkfight@fn_fe353baa@@UAE_NII@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// hulkfight::motion::BallAndChainReturnAction::vfunc_3 @ 0x00182660
namespace hulkfight { namespace motion {
bool BallAndChainReturnAction::vfunc_3(unsigned,unsigned) {
 if (!source) return false;
 Actor_182660* actor=source->FUN_000592a0();
 Lookup_182660* lookup=actor->FUN_00059a30();
 Item_182660* item=lookup->FUN_00035ef0(settings->key);
 if (!item) return false;
 origin=*item->FUN_001d6b40();
 Vec_182660 position=settings->position;
 Vec_182660 result;
 TransformHolder* holder=actor->FUN_00059a40();
 holder->transform.FUN_00221c40()->FUN_0022c2b0(&position, &result);
 direction=result;
 direction.x-=origin.x; direction.y-=origin.y; direction.z-=origin.z;
 length=direction.FUN_0022d110();
 value=settings->value;
 return true;
}
} }

} // namespace fn_fe353baa

// 0x00182740 hulkfight::motion::BallAndChainReturnAction::vfunc_5 (1355 B): equivalent/0x00182740.cpp [wrapped: conflict: hulkfight::motion::BallAndChainReturnAction]
// sym: ?vfunc_5@BallAndChainReturnAction@motion@hulkfight@fn_00182740@@UAE_NHM@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00182740 {
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 20/20; --wine 623 inputs)
// hulkfight::motion::BallAndChainReturnAction::vfunc_5 @ 0x00182740
// hulkfight::motion::BallAndChainReturnAction::vfunc_5 @ 0x00182740
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

struct V3_182740 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_182740 *other, float eps);
};

struct Mat_182740 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c120();
    void FUN_0022c2b0(V3_182740 *in, V3_182740 *out);
    void FUN_0022ca90(Mat_182740 *a, Mat_182740 *b);
};

class Obj_182740 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Weapon_182740 {
public:
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
    virtual Mat_182740 *v15();
};

struct Xform_182740 {
    Mat_182740 *FUN_00221c40();
};

struct Skeleton_182740 {
    char pad0[0x10];
    Xform_182740 xform;
};

struct Table_182740 {
    char pad0[0x1c];
    Mat_182740 *xforms;     // 0x1c
    unsigned FUN_002843a0(unsigned lo, unsigned hi);
};

struct Holder_182740 {
    char pad0[0x120];
    Table_182740 *table;    // 0x120
    char pad124[0x328 - 0x124];
    Obj_182740 *held;       // 0x328
    Weapon_182740 *FUN_00035ef0(unsigned slot);
    void FUN_0003acf0(unsigned id, Weapon_182740 *w, int a, int b, int c, Mat_182740 *m);
};

struct Owner_182740 {
    Holder_182740 *FUN_00059a30();
    Skeleton_182740 *FUN_00059a40();
};

struct Source_182740 {
    Owner_182740 *FUN_000592a0();
};

struct Config_182740 {
    char pad0[0x14];
    unsigned slot;          // 0x14
    char pad18[4];
    float f1c;              // 0x1c
    float f20;              // 0x20
    float f24;              // 0x24
    float f28;              // 0x28
    V3_182740 v2c;          // 0x2c
    V3_182740 v38;          // 0x38
    char pad44[4];
    char f48[8];            // 0x48
    V3_182740 v50;          // 0x50
    char pad5c[4];
    unsigned f60;           // 0x60
    unsigned f64;           // 0x64
    V3_182740 v68;          // 0x68
};

struct Ray_182740 {
    bool FUN_00201e00(V3_182740 *a, V3_182740 *b, int c, V3_182740 *d, V3_182740 *e, int f, int g);
};

struct World {
    char pad0[0x24];
    Ray_182740 *ray;        // 0x24
};

struct Decal_182740 {
    unsigned FUN_00283ca0(void *a, V3_182740 *b, V3_182740 *c, float d);
    void FUN_00283450(unsigned h, V3_182740 *b, V3_182740 *c, float d);
};
Decal_182740 *FUN_0027f250();

extern "C" void __cdecl FUN_00224db0(Mat_182740 *m, V3_182740 *up, V3_182740 *fwd);
extern "C" int __cdecl FUN_00098190(float dt, float f3c, float f20, int zero0, Obj_182740 *held, float f24, V3_182740 *pos, V3_182740 *dir, int z1, int z2, int z3, int one);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memcpy(void *d, const void *s, unsigned int n);
#endif


struct Frame_182740 {
    V3_182740 Q;            // 0x10
    char pad1c[3];
    bool flag;              // 0x1f
    V3_182740 P;            // 0x20
    V3_182740 d;            // 0x2c
    V3_182740 in;           // 0x38
    V3_182740 D2;           // 0x44
    Weapon_182740 *weapon;  // 0x50
    float nL;               // 0x54
    Holder_182740 *holder;  // 0x58
    unsigned slot;          // 0x5c
    Owner_182740 *owner;    // 0x60
    V3_182740 end;          // 0x64
    V3_182740 nd;           // 0x70
    V3_182740 start;        // 0x7c
    Mat_182740 rot;         // 0x88
    V3_182740 hitB;         // 0xc8
    V3_182740 hitA;         // 0xd4
    Mat_182740 wmat;        // 0xe0
    Mat_182740 inv;         // 0x120
};

namespace hulkfight { namespace motion {

class BallAndChainReturnAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int state, float dt);
    char pad04[0x1c - 4];
    Config_182740 *cfg;     // 0x1c
    Source_182740 *source;  // 0x20
    V3_182740 pos;          // 0x24
    V3_182740 dir;          // 0x30
    float speed;            // 0x3c
    float dist;             // 0x40
    unsigned decal;         // 0x44
};

bool BallAndChainReturnAction::vfunc_5(int state, float dt)
{
    if (state != 1)
        return true;
    if (source == 0)
        return false;

    Frame_182740 f;
    f.owner = source->FUN_000592a0();
    f.holder = f.owner->FUN_00059a30();
    f.slot = cfg->slot;
    f.weapon = f.holder->FUN_00035ef0(f.slot);
    f.in = cfg->v2c;
    f.owner->FUN_00059a40()->xform.FUN_00221c40()->FUN_0022c2b0(&f.in, &f.P);

    f.d = f.P;
    f.d.x = f.d.x - pos.x;
    f.d.y = f.d.y - pos.y;
    f.d.z = f.d.z - pos.z;
    f.d.FUN_0022d110();

    hulk_freg spd = dt * cfg->f1c + speed;   // `fst [this+0x3c]`: the register keeps the unrounded sum for the next product
    dist = dist - spd * dt;
    speed = spd;
    if (f.holder->held != 0)
        FUN_00098190(dt, speed, cfg->f20, 0, f.holder->held, cfg->f24, &pos, &dir, 0, 0, 0, 1);

    float s = dt * speed;
    f.Q.x = dir.x * s + pos.x;
    volatile float qy = dir.y * s;
    volatile float qz = dir.z * s;
    f.Q.y = qy + pos.y;
    f.Q.z = qz + pos.z;
    f.D2.x = f.Q.x - f.P.x;
    f.D2.y = f.Q.y - f.P.y;
    f.D2.z = f.Q.z - f.P.z;
    f.D2.FUN_0022d110();

    float L = dist;
    f.Q.x = f.P.x + f.D2.x * L;
    volatile float my = f.D2.y * L;
    volatile float mz = f.D2.z * L;
    f.Q.y = f.P.y + my;
    f.Q.z = f.P.z + mz;

    if (DAT_004dd700->ray->FUN_00201e00(&f.P, &f.Q, 1, &f.hitA, &f.hitB, 0, 0)) {
        dir = f.d;
        f.nL = -dist;
        volatile float hx = f.nL * dir.x;
        f.Q.x = f.P.x + hx;
        f.Q.y = f.P.y + dir.y * f.nL;
        f.Q.z = f.P.z + dir.z * f.nL;
    }

    f.flag = true;
    if (dist <= cfg->f28) {
        f.flag = false;
        f.Q = f.P;
    } else {
        f.d.x = f.P.x - f.Q.x;
        f.d.y = f.P.y - f.Q.y;
        f.d.z = f.P.z - f.Q.z;
        f.d.FUN_0022d110();
    }

    if (f.weapon != 0) {
        memcpy(&f.wmat, f.weapon->v15(), sizeof(Mat_182740));
        f.in = cfg->v50;
        f.wmat.FUN_0022c2b0(&f.in, &f.end);
    } else {
        f.end = pos;
    }

    Table_182740 *table = f.holder->table;
    unsigned idx = table->FUN_002843a0(cfg->f60, cfg->f64);
    if (idx == 0xffff)
        idx = 0;
    f.in = cfg->v68;
    table->xforms[idx].FUN_0022c2b0(&f.in, &f.start);

    Decal_182740 *dm = FUN_0027f250();
    if (decal == 0)
        decal = dm->FUN_00283ca0(&cfg->f48, &f.end, &f.start, 1000.0f);
    else
        dm->FUN_00283450(decal, &f.end, &f.start, 1000.0f);

    if (f.weapon != 0) {
        memcpy(&f.inv, f.owner->FUN_00059a40()->xform.FUN_00221c40(), sizeof(Mat_182740));
        f.inv.FUN_0022c120();
        f.rot.FUN_0022b980();
        f.in = cfg->v38;
        f.nd.x = -f.d.x;
        f.nd.y = -f.d.y;
        f.nd.z = -f.d.z;
        if (!f.in.FUN_0022d2b0(&f.nd, 9.99999974737875e-06f))
            FUN_00224db0(&f.rot, &f.in, &f.nd);
        f.rot.m[12] = f.Q.x;
        f.rot.m[13] = f.Q.y;
        f.rot.m[14] = f.Q.z;
        pos = f.Q;
        f.wmat.FUN_0022b980();
        f.wmat.FUN_0022ca90(&f.rot, &f.inv);
        f.holder->FUN_0003acf0(f.slot, f.weapon, 0, 0, 0, &f.wmat);
    }
    return f.flag;
}

} }
} // namespace fn_00182740
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fe353baa {

// 0x00182c90 hulkfight::motion::BallAndChainReturnAction::vfunc_4 (50 B): matches/0x00182c90.cpp
// sym: ?vfunc_4@BallAndChainReturnAction_182c90@fn_fe353baa@@QAEXXZ
void BallAndChainReturnAction_182c90::vfunc_4() {
    Helper_182c90* x = ((Helper_182c90 *)((owners::Object_592a0 *)(((Helper_182c90*)*(void**)(pad + 0x20))))->FUN_000592a0());
    x = x->f59a30();
    ((owners::C_35ef0 *)x)->FUN_00035ef0((hulk_intptr)(*(int*)(*(char**)(pad + 0x1c) + 0x14)));
    x = f27f250();
    x->f27ffb0(*(int*)(pad + 0x44));
}

} // namespace fn_fe353baa
