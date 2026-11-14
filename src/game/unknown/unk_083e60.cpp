// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00083e60..0x00085d90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb2690e0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb2690e0 {} using namespace fn_fb2690e0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_fb2690e0 {
struct Mat {
    float m[16];
    void FUN_0022b980();
};
struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};
hulk_freg __cdecl FUN_00018a20(float x);
class Rig {
public:
    char pad00[0x60];
    Vec3 center;
    char pad6c[0x84 - 0x6c];
    Vec3 u84;
    Vec3 o90;
    Vec3 c9c;
    Vec3 ea8;
    float ang;
    float rad;
    void FUN_00083e60(Vec3 U, Vec3 V, Vec3 P);
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Vec3_843c0 {
    float x, y, z;
};
struct NameHolder_843c0 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027af50();
};
class Mover_843c0;
union Args_843c0 {
    struct {
        float dirX;
        float unused;
        float dirZ;
        float dt;
    } in;
    int sign;
    NameHolder_843c0 name;
};
struct Registry_843c0 {
    bool FUN_001dd930(void* key, NameHolder_843c0* name);
};
struct Controller_843c0 {
    void FUN_001ebe10(Mover_843c0* who, NameHolder_843c0* name, const char* effect);
};
} // namespace fn_fb2690e0
struct World {
    char pad00[0xc];
    Registry_843c0* registry;         // 0x0c
    char pad10[0x34 - 0x10];
    Controller_843c0* controller;     // 0x34
};
namespace fn_fb2690e0 {
class Mover_843c0 {
public:
    bool FUN_000843c0(Args_843c0 args);

    char pad00[0x10];
    int state;                  // 0x10
    char pad14[4];
    float rate;                 // 0x18
    char pad1c[0x34 - 0x1c];
    void* key;                  // 0x34
    char pad38[0x60 - 0x38];
    Vec3_843c0 pos;                   // 0x60
    Vec3_843c0 axis;                  // 0x6c
    char pad78[0x84 - 0x78];
    Vec3_843c0 heading;               // 0x84
    Vec3_843c0 origin;                // 0x90
    Vec3_843c0 from;                  // 0x9c
    Vec3_843c0 to;                    // 0xa8
    float fb4;                  // angle
    float fb8;
    float fbc;
    float fc0;
};
struct V3_84920 {
    float x, y, z;
    void FUN_0022d180();
};
union FloatBits_84920 {
    float f;
    unsigned int u;
};
struct Frame_84920 {
    float dot;
    V3_84920 lo;
    V3_84920 hi;
};
class Tracker_84920 {
public:
    char pad00[0x10];
    int state;
    char pad14[0x38 - 0x14];
    V3_84920 a;
    V3_84920 b;
    V3_84920 c;
    char pad5c[0xbc - 0x5c];
    int fbc;
    void FUN_00083e60(V3_84920 d1, V3_84920 d2, V3_84920 p);
    void FUN_00084920(V3_84920 na, V3_84920 nb, V3_84920 nc);
};
class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
} // namespace fn_fb2690e0
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fb2690e0 {
class Shader_85d30 : public Obj {
    char pad[28];

  public:
    Shader_85d30();
};
class Obj_85d70 {
  public:
    virtual void f();
    virtual void g();
};


// 0x00083e60 FUN_00083e60 (1367 B): equivalent/0x00083e60.cpp
// sym: ?FUN_00083e60@Rig@fn_fb2690e0@@QAEXUVec3@2@00@Z @94e665a45ff6 @w6c16e1aa810c
// STATUS: equivalent (tools/equiv.py level 3: 15598 inputs, branch coverage 10/10)
// FUN_00083e60 @ 0x00083e60
void Rig::FUN_00083e60(Vec3 U, Vec3 V, Vec3 P)
{
    double dd = V.z * U.z + V.y * U.y + V.x * U.x;
    volatile float dm = (float)dd;
    FloatBits t;
    t.f = (float)(dd - 1.0f);
    t.u &= 0x7fffffff;
    if (t.f <= 1e-05f) {
        rad = 0.0f;
        ang = 0.0f;
        u84 = U;
        return;
    }
    t.f = (float)(dd + 1.0f);
    t.u &= 0x7fffffff;
    float dxr = P.x - center.x;
    if (t.f <= 1e-05f) {
        V.x = dxr;
        V.y = P.y - center.y;
        ang = 3.1415927f;
        V.z = P.z - center.z;
        rad = (float)(sqrt(V.z * V.z + V.y * V.y + V.x * V.x) * 0.5f);
        V.FUN_0022d180();
        c9c = center;
        ea8 = P;
        float r = rad;
        P.x = V.x * r;
        P.y = V.y * r;
        double rz = r * V.z;
        o90.z = (float)(rz + center.z);
        o90.x = P.x + center.x;
        o90.y = P.y + center.y;
        u84 = U;
        return;
    }
    Vec3 D;
    volatile float dxs = dxr;
    D.x = dxs;
    D.y = P.y - center.y;
    double dz80 = P.z - center.z;
    D.z = (float)dz80;
    float len0 = (float)sqrt(dz80 * D.z + D.y * D.y + dxs * dxs);
    double a80 = FUN_00018a20(-dm);
    ang = (float)a80;
    t.f = (float)(a80 - 1.57079637f);
    t.u &= 0x7fffffff;
    if (t.f <= 1e-05f) {
        D.FUN_0022d180();
        double ang2 = FUN_00018a20(D.z * V.z + D.y * V.y + D.x * V.x);
        volatile float S = (float)(sin(ang2) * len0);
        double C = cos(ang2) * len0;
        double M = (S < C) ? (double)S : C;
        double R80 = tan(ang * 0.5f) * M;
        rad = (float)R80;
        double sx = U.x * S;
        double sy = U.y * S;
        volatile float sz = U.z * S;
        P.x = sx + center.x;
        P.y = sy + center.y;
        P.z = sz + center.z;
        volatile float wx = U.x * R80;
        volatile float wy = U.y * R80;
        double wz = R80 * U.z;
        c9c.x = P.x - wx;
        c9c.y = P.y - wy;
        c9c.z = (float)(P.z - wz);
        float r2 = rad;
        volatile float vx = V.x * r2;
        volatile float vy = V.y * r2;
        double vz = r2 * V.z;
        P.z = vz + P.z;
        ea8.z = P.z;
        ea8.x = vx + P.x;
        ea8.y = vy + P.y;
    } else {
        rad = (float)(tan(a80 * 0.5f) * len0);
        c9c = center;
        double vx = V.x * len0;
        volatile float vy = V.y * len0;
        volatile float vz = V.z * len0;
        P.z = vz + P.z;
        ea8.z = P.z;
        ea8.x = vx + P.x;
        ea8.y = vy + P.y;
    }
    int sign = 1;
    if (U.z * V.x - V.z * U.x < 0.0f)
        sign = -1;
    Mat M;
    M.FUN_0022b980();
    ((owners::Mat_22ba70 *)&M)->FUN_0022ba70(sign * 1.57079637f);
    Vec3 Uc = U;
    ((owners::Obj_22d260 *)&Uc)->FUN_0022d260((owners::Obj_22d260 *)(Mat *)(&M));
    Uc.FUN_0022d180();
    float r3 = rad;
    volatile float ux = Uc.x * r3;
    volatile float uy = Uc.y * r3;
    double uz = r3 * Uc.z;
    V.z = uz + c9c.z;
    o90.z = V.z;
    o90.x = ux + c9c.x;
    o90.y = uy + c9c.y;
    u84 = U;
}


// 0x000843c0 FUN_000843c0 (587 B): equivalent/0x000843c0.cpp
// sym: ?FUN_000843c0@Mover_843c0@fn_fb2690e0@@QAE_NTArgs_843c0@2@@Z @fe2d0801dcbf @w667c06f948f0
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 12/12)
// FUN_000843c0 @ 0x000843c0
bool Mover_843c0::FUN_000843c0(Args_843c0 args)
{
    Vec3_843c0 d;
    double x;

    union { float f; unsigned int u; } a;
    a.f = fb4 - 3.14159274f;
    a.u &= 0x7fffffff;
    if (a.f <= 1e-5f) {
        x = fb4;
        d.x = to.x - from.x;
        d.z = to.z - from.z;
    } else {
        x = 3.14159274f - fb4;
        d.x = args.in.dirX;
        d.z = args.in.dirZ;
    }

    float n = args.in.dt * rate + fbc;
    double y = x * fb8;
    if (n >= y)
        return false;

    args.sign = 1;
    float r = (float)(n / y);
    float s = (float)(r * x);
    if ((double)d.x * heading.z - (double)d.z * heading.x < 0.0)
        args.sign = -1;

    Matrix m;
    m.FUN_0022b980();
    ((owners::Mat_22ba70 *)&m)->FUN_0022ba70((float)args.sign * s);

    axis = heading;
    ((owners::Obj_22d260 *)&axis)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)(&m));

    d.x = from.x - origin.x;
    d.y = from.y - origin.y;
    d.z = from.z - origin.z;
    ((owners::Obj_22d260 *)&d)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)(&m));

    pos.x = d.x + origin.x;
    pos.y = d.y + origin.y;
    pos.z = d.z + origin.z;
    int st = state;
    fbc = n;
    if (st == 0xf && r >= fc0) {
        state = 0x10;
        heading = axis;
        fbc = 0.0f;
        Registry_843c0* registry = DAT_004dd700->registry;
        Controller_843c0* controller = DAT_004dd700->controller;
        args.name.FUN_0027af00();
        if (registry->FUN_001dd930(key, &args.name))
            controller->FUN_001ebe10(this, &args.name, "skid");
        args.name.FUN_0027af50();
    }
    return true;
}

} // namespace fn_fb2690e0

// 0x00084610 FUN_00084610 (530 B): equivalent/0x00084610.cpp [wrapped: conflict: World]
// sym: ?FUN_00084610@Pointer@fn_00084610@@QAEXM@Z @9b46b8009f6a @we7fde5ddf64f
namespace fn_00084610 {
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 24/24)
// FUN_00084610 @ 0x00084610
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

struct Vec3_84610 {
    float x, y, z;
    void FUN_0022d180();
};

struct Hit_84610 {
    char pad00[8];
    Vec3_84610 *pos;
};

struct Tracker_84610 {
    bool FUN_001dd800(int handle);
    void FUN_001dd840(int handle, int flag);
};

struct Level_84610 {
    bool FUN_002ee140(Hit_84610 *hit, Vec3_84610 *from, Vec3_84610 *to, int flags);
};

struct Cursor_84610 {
    int FUN_000797b0(int a, int b);
    bool FUN_0007c930(Vec3_84610 v, int c);
};

struct World {
    char pad00[0x0c];
    Tracker_84610 *tracker;       // 0x0c
    struct {
        char pad00[8];
        Level_84610 *level;       // 0x08
    } *world;               // 0x10
    char pad14[0x4c - 0x14];
    Cursor_84610 *cursor;         // 0x4c
};


extern "C" Hit_84610 *FUN_00202f00();

class Pointer {
public:
    char pad00[8];
    int f08;
    int f0c;
    int mode;           // 0x10
    char pad14[4];
    float value;        // 0x18
    float limit;        // 0x1c
    char pad20[0x34 - 0x20];
    int handle;         // 0x34
    char pad38[0x60 - 0x38];
    Vec3_84610 pos;           // 0x60
    Vec3_84610 dir;           // 0x6c

    void FUN_00084610(float dt);
};

void Pointer::FUN_00084610(float dt)
{
    struct Frame {
        Vec3_84610 hit;
        Vec3_84610 to;
        Vec3_84610 from;
    } fr;

    if (DAT_004dd700->tracker->FUN_001dd800(handle)) {
        DAT_004dd700->tracker->FUN_001dd840(handle, 0);
        Hit_84610 *h = FUN_00202f00();
        DAT_004d2a3c = 2;
        (*(char*)&DAT_004d2a40) = 0;
        (*(char*)&DAT_00554c1c) = 1;
        (*(float*)&DAT_00554c18) = 0.35f;
        dir.FUN_0022d180();
        fr.hit.z = dir.z * 15.0f;
        fr.from.x = pos.x;
        fr.from.z = pos.z;
        fr.from.y = pos.y;
        fr.to.x = dir.x * 15.0f + pos.x;
        fr.to.y = dir.y * 15.0f + pos.y;
        fr.to.z = fr.hit.z + pos.z;
        if (DAT_004dd700->world->level->FUN_002ee140(h, &fr.from, &fr.to, 0)) {
            fr.hit.x = h->pos->x;
            fr.hit.y = h->pos->y;
            fr.hit.z = h->pos->z;
            if (fr.hit.x > 10.0f)
                value = value - dt * 5.0f;
            else if (fr.hit.x > 5.0f)
                value = value - dt * 10.0f;
            else
                value = 0;
        } else {
            if (mode != 1 && mode != 2)
                value = dt * 5.0f + value;
        }
        if (!(value >= 0.0f && value <= limit)) {
            if (value > limit)
                value = limit;
            else
                value = 0.0f;
        }
        DAT_004dd700->tracker->FUN_001dd840(handle, 1);
    } else {
        Cursor_84610 *c = DAT_004dd700->cursor;
        int r = c->FUN_000797b0(f08, f0c);
        if (c->FUN_0007c930(pos, r)) {
            value = 0;
            return;
        }
        if (mode != 1 && mode != 2)
            value = limit;
    }
}
} // namespace fn_00084610
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00084830 FUN_00084830 (230 B): equivalent/0x00084830.cpp [wrapped: conflict: World]
// sym: ?FUN_00084830@Object@fn_00084830@@QAEXI@Z @ad40e5efd9a9 @w18a69e9267ac
namespace fn_00084830 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00084830 @ 0x00084830
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

struct Vec_84830 { float x,y,z; hulk_freg FUN_0022d110();  };
struct Matrix { float m[16]; void FUN_0022b980();  void FUN_0022bec0(Vec_84830*,Vec_84830*);  };
struct Renderer_84830 { void FUN_001dd470(unsigned,Matrix*,unsigned); };
struct World { char pad[12]; Renderer_84830* renderer; }; 
struct Object { char pad[0x34]; unsigned id; char pad2[0x28]; Vec_84830 position; Vec_84830 direction; void FUN_00084830(unsigned arg); };
void Object::FUN_00084830(unsigned arg) { direction.y=0.0f; direction.FUN_0022d110(); union { float f; unsigned u; } length; length.f=direction.x*direction.x+direction.y*direction.y+direction.z*direction.z; length.u &= 0x7fffffff; if (!(length.f<=1e-05f)) { Matrix rotation; rotation.FUN_0022b980(); ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70(1.5707963705062866f); ((owners::Obj_22d260 *)&direction)->FUN_0022d260((owners::Obj_22d260 *)(&rotation)); Matrix transform; transform.FUN_0022b980(); Vec_84830 up; up.x=0.0f; up.y=1.0f; up.z=0.0f; transform.FUN_0022bec0(&direction,&up); ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(Vec_84830 *)(&position)); DAT_004dd700->renderer->FUN_001dd470(id,&transform,arg); } }
} // namespace fn_00084830
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fb2690e0 {

// 0x00084920 FUN_00084920 (795 B): equivalent/0x00084920.cpp
// sym: ?FUN_00084920@Tracker_84920@fn_fb2690e0@@QAEXUV3_84920@2@00@Z @acd3ee53d922 @w85f376b82118
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 10/10)
// FUN_00084920 @ 0x00084920
void Tracker_84920::FUN_00084920(V3_84920 na, V3_84920 nb, V3_84920 nc)
{
    Frame_84920 f;
    FloatBits_84920 t;
    if (state == 3) {
        V3_84920& thisd = f.hi;
        V3_84920& argd = f.lo;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        t.f = argd.z * thisd.z + argd.y * thisd.y + argd.x * thisd.x - 1.0f;
        t.u &= 0x7fffffff;
        if (t.f <= 1e-05f) {
            state = 9;
        } else {
            FUN_00083e60(thisd, argd, nb);
            state = 5;
        }
    } else if (state == 4) {
        V3_84920& thisd = f.lo;
        V3_84920& argd = f.hi;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        t.f = argd.z * thisd.z + argd.y * thisd.y + argd.x * thisd.x - 1.0f;
        t.u &= 0x7fffffff;
        if (t.f <= 1e-05f) {
            state = 10;
        } else {
            FUN_00083e60(thisd, argd, nb);
            state = 6;
        }
    } else if (state == 13) {
        V3_84920& thisd = f.lo;
        V3_84920& argd = f.hi;
        thisd.x = c.x - b.x;
        thisd.y = c.y - b.y;
        thisd.z = c.z - b.z;
        argd.x = nc.x - nb.x;
        argd.y = nc.y - nb.y;
        argd.z = nc.z - nb.z;
        thisd.FUN_0022d180();
        argd.FUN_0022d180();
        FUN_00083e60(thisd, argd, nb);
        fbc = 0;
        state = 14;
    }
    a = na;
    b = nb;
    c = nc;
}

} // namespace fn_fb2690e0

// 0x00084c40 FUN_00084c40 (4083 B): equivalent/0x00084c40.cpp [wrapped: conflict: World]
// sym: ?FUN_00084c40@Mover_84c40@fn_00084c40@@QAEXM@Z @805ae7d41acc @w4fc537d10165
namespace fn_00084c40 {
// STATUS: equivalent (tools/equiv.py level 3: 3062 inputs, branch coverage 140/142, incomplete; Wine build 3062 inputs, 140/142)
// FUN_00084c40 @ 0x00084c40
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

struct V3_84c40 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_0022d180();
    hulk_freg FUN_000111f0();
    void FUN_00083be0(V3_84c40 *a, V3_84c40 *b);
};

struct Matrix {
    float m[16];
};

struct NameHolder_84c40 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027af50();
};

struct Args_84c40 {
    float x, y, z, dt;
};

struct Rng_84c40 {
    int s0, s1;
    hulk_freg FUN_000787e0(float lo, float hi);
};

struct Probe_84c40 {
    bool FUN_00092940(int id);
};

struct Holder_84c40 {
};

struct Volume_84c40 {
    bool FUN_001c4010(float *v4);
};

struct CamSub {
    bool FUN_00059a50(V3_84c40 *out);
};

struct Camera {
    char pad00[0x10];
    CamSub *sub;
};

struct CamOwner {
    char pad00[0x124];
    Camera *camera;
};

struct Registry_84c40 {
    void FUN_001dd520(int key, Matrix *out);
    bool FUN_001dd930(int key, NameHolder_84c40 *name);
    bool FUN_001dd800(int key);
};

struct Mover_84c40;

struct Controller_84c40 {
    void FUN_001ebe10(Mover_84c40 *who, NameHolder_84c40 *name, const char *effect);
};

struct Manager_84c40 {
    void FUN_0007da40(void *p);
};

struct World {
    char pad00[0x0c];
    Registry_84c40 *registry;     // 0x0c
    char pad10[0x20 - 0x10];
    CamOwner *camOwner;     // 0x20
    char pad24[0x34 - 0x24];
    Controller_84c40 *controller; // 0x34
    char pad38[0x4c - 0x38];
    Manager_84c40 *manager;       // 0x4c
    char pad50[4];
    Holder_84c40 *holder;         // 0x54
};


extern "C" Rng_84c40 *FUN_000964d0();
Volume_84c40 *FUN_001c3d90();
extern "C" float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
bool __cdecl FUN_00018960(float a, float b, float c);
V3_84c40 *__cdecl FUN_00083dd0(V3_84c40 *out, float s, V3_84c40 *v);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(float angle, V3_84c40 *v);
hulk_freg __cdecl FUN_00224f10(V3_84c40 *v);
hulk_freg __cdecl FUN_00224fc0(float a, float b);

union FloatBits_84c40 {
    float f;
    unsigned int u;
};

struct Frame_84c40 {
    char pad0[3];
    char b13;                       // 0x13
    union { Rng_84c40 *rng; float lo; float t; unsigned int u; int i; } s14;
    union { float dy; unsigned int dyu; float B; } s18;
    V3_84c40 tmp;                         // 0x1c
    union { Controller_84c40 *ctrl; float lo2; float t28; } s28;
    V3_84c40 dir;                         // 0x2c
    union { Registry_84c40 *reg; float A; } s38;
    V3_84c40 d;                           // 0x3c
    union { float len; NameHolder_84c40 name; } s48;
    V3_84c40 hdir;                        // 0x50
    V3_84c40 fwd;                         // 0x5c
    V3_84c40 camPos;                      // 0x68
    float vol[4];                   // 0x74
    Matrix m;                       // 0x84
};

class Mover_84c40 {
public:
    char pad00[0x10];
    int state;              // 0x10
    char active;            // 0x14
    char pad15[3];
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    char pad2c;
    char f2d;
    char pad2e[2];
    int f30;
    int key;                // 0x34
    char pad38[8];
    int f40;
    V3_84c40 f44;
    V3_84c40 f50;
    char pad5c[4];
    V3_84c40 pos;                 // 0x60
    V3_84c40 f6c;
    V3_84c40 f78;
    V3_84c40 f84;
    char pad90[0x9c - 0x90];
    V3_84c40 f9c;
    V3_84c40 fa8;
    float fb4;
    float fb8;
    float fbc;
    float fc0;

    bool FUN_000843c0(V3_84c40 dir, float dt);
    void FUN_00083e60(V3_84c40 d1, V3_84c40 d2, V3_84c40 p);
    void FUN_00084610(float dt);
    void FUN_00084830(float dt);
    void FUN_00084c40(float dt);
};

void Mover_84c40::FUN_00084c40(float dt)
{
    Frame_84c40 fr;
    World *g = DAT_004dd700;
    Probe_84c40 *probe = ((Probe_84c40 *)((owners::A_86340 *)(g->holder))->FUN_00086340());
    fr.b13 = probe->FUN_00092940(0x25);
    fr.s38.reg = DAT_004dd700->registry;
    fr.s28.ctrl = DAT_004dd700->controller;
    CamOwner *owner = DAT_004dd700->camOwner;
    fr.s14.rng = FUN_000964d0();

    fr.vol[0] = pos.x;
    fr.vol[1] = pos.y;
    fr.vol[2] = pos.z;
    fr.vol[3] = 5.0f;
    if (FUN_001c3d90()->FUN_001c4010(fr.vol)) {
        f2d = 1;
    } else if (f2d) {
        f30 = 0;
        f2d = 0;
    } else {
        f30++;
    }

    Camera *cam = owner->camera;
    cam->sub->FUN_00059a50(&fr.camPos);
    fr.s38.reg->FUN_001dd520(key, &fr.m);
    fr.d.x = fr.camPos.x - fr.m.m[12];
    fr.d.y = 0;
    fr.s18.dy = fr.camPos.y - fr.m.m[13];
    fr.d.z = fr.camPos.z - fr.m.m[14];
    fr.s48.len = fr.d.FUN_0022d110();
    fr.fwd.x = -1.0f;
    fr.fwd.y = 0;
    fr.fwd.z = 0;
    ((owners::M_22c3b0 *)&(fr.m))->FUN_0022c3b0((float *)(V3_84c40 *)(&fr.fwd), (float *)(V3_84c40 *)(&fr.dir));

    if (!active) {
        fr.s18.dyu &= 0x7fffffff;
        if (fr.s18.dy < 4.0f && !probe->FUN_00092940(0x25)
            && (fr.s48.len < f28
                || (fr.s48.len < f24
                    && ((fr.dir.y * fr.d.y + fr.dir.x * fr.d.x) + fr.dir.z * fr.d.z) > 0.7f))) {
            active = 1;
            ((owners::C_35660 *)cam)->FUN_00035660((int *)(V3_84c40 *)(&fr.hdir));
            if (((fr.hdir.y * fr.d.y + fr.hdir.x * fr.d.x) + fr.hdir.z * fr.d.z) < 0.0f) {
                state = 0xf;
                f78.FUN_00083be0(&fr.d, &fr.dir);
                ((owners::Vec_83ba0 *)&f78)->FUN_00083ba0((const owners::Vec_83ba0 *)(V3_84c40 *)(&fr.dir));
                f78.FUN_0022d180();
                V3_84c40 &p = fr.fwd;
                fr.s18.dy = f28;
                fr.tmp.x = (fr.dir.x + f78.x) * fr.s18.dy;
                p.z = fr.dir.z + f78.z;
                p.y = (fr.dir.y + f78.y) * fr.s18.dy + pos.y;
                p.x = fr.tmp.x + pos.x;
                p.z = p.z * fr.s18.dy + pos.z;
                FUN_00083e60(fr.dir, f78, p);
                fbc = 0;
                fc0 = fr.s14.rng->FUN_000787e0(0.3f, 1.3f);
                if (fc0 > 0.9f)
                    fc0 = 1.3f;
                fr.s48.name.FUN_0027af00();
                if (fr.s38.reg->FUN_001dd930(key, &fr.s48.name)) {
                    fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "skid");
                    if (((owners::Random_11330 *)(fr.s14.rng))->FUN_00011330(2) == 0)
                        fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "horn");
                }
                fr.s48.name.FUN_0027af50();
            } else {
                state = 0x11;
                fr.tmp.z = -fr.d.z;
                f78.x = -fr.d.x;
                f78.y = -fr.d.y;
                f78.z = fr.tmp.z;
                fr.s48.name.FUN_0027af00();
                if (fr.s38.reg->FUN_001dd930(key, &fr.s48.name))
                    fr.s28.ctrl->FUN_001ebe10(this, &fr.s48.name, "skid");
                fr.s48.name.FUN_0027af50();
            }
        }
    }

    if (active) {
        if (((int)((owners::Obj_1dc0d0 *)(fr.s38.reg))->FUN_001dc0d0((hulk_intptr)key)) == 0)
            return;
    }

    switch (state) {
    case 3:
    case 4:
    case 0xd:
        return;
    case 0xf: {
        fr.s14.lo = 0;
        f18 = dt * f20 + f18;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, ((float*)&DAT_003ff9ac));
        if (FUN_000843c0(f78, dt))
            break;
        f6c = fr.dir;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 0x10: {
        fr.s28.lo2 = 0;
        f18 = f18 - dt * 10.0f;
        f18 = FUN_000186b0(&f18, &fr.s28.lo2, ((float*)&DAT_003ff9ac));
        fr.s28.t28 = f18 * dt;
        double cr = (double)f78.z * f84.x - (double)f84.z * f78.x;
        if (cr == 0.0)
{
            fr.s14.i = (int)(((owners::Random_11330 *)(fr.s14.rng))->FUN_00011330(1) * 2 - 1);
            cr = fr.s14.i;
            if (fr.s14.i < 0)
                cr += 4294967296.0;
        }
        // x87: the sum is stored to fbc (fst) and the unrounded register copy is divided by fb8
        hulk_freg sum = fr.s28.t28 + fbc;
        fbc = sum;
        f6c = f84;
        fr.s18.B = sum / fb8;
        if (cr > 0.0)
            FUN_00224d70(fr.s18.B, &f6c);
        else
            FUN_00224d70(-fr.s18.B, &f6c);
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, fr.s28.t28, &f84)));
        if (f18 == 0.0f) {
            if (((fr.dir.y * fr.d.y + fr.dir.x * fr.d.x) + fr.dir.z * fr.d.z) < 0.0f) {
                state = 0xf;
                fbc = 100.0f;
            } else {
                state = 0x12;
                f84 = f6c;
            }
        }
        break;
    }
    case 0x11: {
        fr.s14.lo = 0;
        f18 = f18 - dt * 20.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, ((float*)&DAT_003ff9ac));
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        if (FUN_00018960(f18, 0.0f, 1e-05f)) {
            state = 0x12;
            f84 = f6c;
        }
        break;
    }
    case 0x12: {
        fr.s14.lo = 0;
        f18 = dt * 10.0f + f18;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, ((float*)&DAT_003ff9b0));
        fr.tmp.z = -fr.d.z;
        f78.x = -fr.d.x;
        f78.y = -fr.d.y;
        f78.z = fr.tmp.z;
        fr.hdir.x = -fr.dir.x;
        fr.hdir.y = -fr.dir.y;
        fr.hdir.z = -fr.dir.z;
        fr.s38.A = FUN_00224f10(&fr.hdir);
        fr.hdir.x = -f84.x;
        fr.hdir.y = -f84.y;
        fr.hdir.z = -f84.z;
        fr.s18.B = FUN_00224f10(&fr.hdir);
        fr.s14.lo = FUN_00224f10(&f78);
        fr.s18.B = FUN_00224fc0(fr.s18.B, fr.s38.A);
        fr.s28.t28 = fr.s18.B;
        fr.s18.dyu &= 0x7fffffff;
        if (fr.s18.B < 0.01745329238474369f) {
            fr.s28.t28 = FUN_00224fc0(fr.s38.A, fr.s14.lo);
            hulk_freg sg = FUN_00083d90(&fr.s28.t28);
            if (sg == 0.0f)
                sg = 1.0f;
            f84.z = DAT_0049bf88;
            f84.x = (*(float*)&DAT_0049bf80);
            f84.y = 0;
            FUN_00224d70(sg * 0.17453293f + fr.s14.lo, &f84);
            fr.tmp.z = -f84.z;
            f84.x = -f84.x;
            f84.y = -f84.y;
            f84.z = fr.tmp.z;
            fr.hdir.x = -f84.x;
            fr.hdir.y = -f84.y;
            fr.hdir.z = -f84.z;
            fr.s18.B = FUN_00224f10(&fr.hdir);
            fr.s28.t28 = FUN_00224fc0(fr.s18.B, fr.s38.A);
        }
        f6c.z = DAT_0049bf88;
        f6c.x = (*(float*)&DAT_0049bf80);
        f6c.y = 0;
        FUN_00224d70(fr.s38.A - (FUN_00083d90(&fr.s28.t28) * dt) * 0.69813174f, &f6c);
        fr.tmp.z = -f6c.z;
        f6c.x = -f6c.x;
        f6c.y = -f6c.y;
        f6c.z = fr.tmp.z;
        ((owners::Vec3_110f0 *)&pos)->FUN_000110f0((owners::Vec3_110f0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 5: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f9c)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 7;
            fbc = 0;
            f6c = fr.dir;
            pos = f9c;
            break;
        }
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 6: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f9c)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 8;
            fbc = 0;
            f6c = fr.dir;
            pos = f9c;
            break;
        }
        f6c = fr.dir;
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 7: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&f44)));
        if (FUN_000843c0(*r, dt))
            break;
        state = 11;
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&fa8)));
        f6c = *r;
        pos = fa8;
        break;
    }
    case 8: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&f44)));
        if (FUN_000843c0(*r, dt))
            break;
        state = 12;
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&fa8)));
        f6c = *r;
        pos = fa8;
        break;
    }
    case 9: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f44)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 11;
            r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&f44)));
            f6c = *r;
            pos = f44;
            break;
        }
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f44)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        f6c = *r;
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 10: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f44)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        fr.s14.t = dt * f18;
        if (fr.tmp.FUN_000111f0() <= fr.s14.t * fr.s14.t) {
            state = 12;
            r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&f44)));
            f6c = *r;
            pos = f44;
            break;
        }
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f44)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        f6c = *r;
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 0xe: {
        if (!fr.s38.reg->FUN_001dd800(key)) {
            DAT_004dd700->manager->FUN_0007da40((char *)this + 8);
            return;
        }
        V3_84c40 *r;
        if (FUN_00018960(fb8, 0.0f, 1e-05f)) {
            state = 0;
            r = ((V3_84c40 *)((owners::Vec3_11250 *)&f44)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
            f6c = *r;
            f6c.FUN_0022d180();
            if (fr.b13)
                f18 = f1c;
            ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
            break;
        }
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&f44)));
        if (FUN_000843c0(*r, dt))
            break;
        state = 0;
        r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&fa8)));
        f6c = *r;
        pos = fa8;
        break;
    }
    case 1: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        f6c = *r;
        if (f6c.FUN_000111f0() <= 16.0f) {
            f18 = 0;
            state = 3;
            return;
        }
        fr.s14.lo = 2.0f;
        f18 = f18 - dt * 5.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &f1c);
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 2: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        f6c = *r;
        if (f6c.FUN_000111f0() <= 16.0f) {
            f18 = 0;
            state = 4;
            return;
        }
        fr.s14.lo = 2.0f;
        f18 = f18 - dt * 5.0f;
        f18 = FUN_000186b0(&f18, &fr.s14.lo, &f1c);
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    case 0: {
        V3_84c40 *r = ((V3_84c40 *)((owners::Vec3_11250 *)&f50)->FUN_00011250((owners::Vec3_11250 *)(V3_84c40 *)(&fr.tmp), (owners::Vec3_11250 *)(V3_84c40 *)(&pos)));
        f6c = *r;
        int t = f40;
        if (t == 0 || t == 5) {
            if (f6c.FUN_000111f0() <= 100.0f)
                state = 1;
        } else if (t == 1 || t == 4) {
            if (f6c.FUN_000111f0() <= 100.0f)
                state = 2;
        } else if (t == 2 || t == 3) {
            if (f6c.FUN_000111f0() <= 16.0f) {
                state = 0xd;
                return;
            }
        }
        f6c.FUN_0022d180();
        if (fr.b13)
            f18 = f1c;
        ((owners::V3_110d0 *)&pos)->FUN_000110d0((owners::V3_110d0 *)(V3_84c40 *)(FUN_00083dd0(&fr.tmp, dt * f18, &f6c)));
        break;
    }
    }

    if (!active && !fr.b13)
        FUN_00084610(dt);
    FUN_00084830(dt);
}
} // namespace fn_00084c40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fb2690e0 {

// 0x00085cd0 FUN_00085cd0 (6 B): matches/0x00085cd0.cpp
// sym: _FUN_00085cd0
extern "C" int FUN_00085cd0(void* /*this, unused: callers pass it (unb4)*/) {
    return DAT_004dd6e4;
}


// 0x00085d30 FUN_00085d30 (61 B): matches/0x00085d30.cpp
// sym: _FUN_00085d30
extern "C" void FUN_00085d30() {
    Shader_85d30* p = new Shader_85d30;
    if (p)
        p->AddRef();
    if ((*(Obj**)&DAT_004dd6e4))
        (*(Obj**)&DAT_004dd6e4)->Release();
    (*(Obj**)&DAT_004dd6e4) = p;
}


// 0x00085d70 FUN_00085d70 (26 B): matches/0x00085d70.cpp
// sym: _FUN_00085d70
// data: globalObj_85d70 = DAT_004dd6e4
extern "C" void FUN_00085d70() {
    if ((*(Obj_85d70**)&DAT_004dd6e4)) {
        (*(Obj_85d70**)&DAT_004dd6e4)->g();
        (*(Obj_85d70**)&DAT_004dd6e4) = 0;
    }
}

} // namespace fn_fb2690e0
