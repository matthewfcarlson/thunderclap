// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00013ec0..0x00014580 (kind game, layer game, confidence medium), dominant class CCollisionAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd8b7d01 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd8b7d01 {} using namespace fn_fd8b7d01;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd8b7d01 {
struct C_13ec0 {
    int second_00059a30();
};
struct B_13ec0 {
};
struct Obj_13ec0 {
    char pad[0x1c];
    B_13ec0* member;
    hulk_intptr target();
};
class A_13ed0 {
  public:
    char pad[0x1c];
    void* p1;
    void* p2;
    char pad2[0x10];
    int m34;
    int m38;
};
struct B_13ed0 {
    char pad[0x10];
    unsigned char flag;
};
struct C_13ed0 {
    char pad[0x11c];
    B_13ed0* b;
};
struct D {
    char pad[0x30];
    int x;
    int y;
};
class X_13ed0 {
  public:
    C_13ed0* Fnf_000592a0();
};
class Y_13ed0 {
  public:
    C_13ed0* Fnf_00059a30();
};
struct Slot_13f20;
struct Slot_13f20 {
    int FUN_001d5e80(int id);
};
struct Pad_13f20 {
    char pad0[0x40];
    int id;
    char pad44[0xec - 0x44];
    Slot_13f20 *slot;
    void FUN_001d6ec0(int a, int b, int c);
};
struct Cfg_13f20 {
    char pad0[0x3c];
    char forceMax;          // 0x3c
    char pad3d[3];
    int count;              // 0x40
    char pad44[4];
    int mode;               // 0x48
    char pad4c[0xb8 - 0x4c];
    float lo;               // 0xb8
    float hi;               // 0xbc
};
struct Ctrl2 {
    char pad0[0x170];
    float mult;             // 0x170
    char pad174[0x30c - 0x174];
    float scale;            // 0x30c
};
struct Player_13f20 {
    char pad0[0x11c];
    Ctrl2 *ctrl;            // 0x11c
    char pad120[0x12c - 0x120];
    int val;                // 0x12c
    char pad130[0x1b28 - 0x130];
    int flag;               // 0x1b28
};
struct PlayerRef_13f20 {
    Player_13f20 *FUN_00059a30();
};
struct Owner_13f20 {
};
struct Item_13f20 {
    char pad0[0x10];
    char dead;              // 0x10
    char pad11[3];
    int kind;               // 0x14
};
struct Holder_13f20 {
    char pad0[0x11c];
    Item_13f20 *item;             // 0x11c
};
struct Target_13f20 {
    char pad0[8];
    Holder_13f20 *holder;         // 8
    int type;               // 0xc
};
struct Text_13f20 {
    char pad0[4];
    void FUN_000d4620(int a, const char *s, int b, int c, float d);
};
struct Hud_13f20 {
    char pad0[4];
    Text_13f20 *text;             // 4
};
struct Flags_13f20 {
    bool FUN_00092940(int id);
};
struct Opt_13f20 {
};
struct Me_13f20;   // (declared here for the next declaration)
} // namespace fn_fd8b7d01
struct World {
    char pad0[0x20];
    struct Me_13f20 *me;          // 0x20
    char pad24[0x3c - 0x24];
    Hud_13f20 *hud;               // 0x3c
    char pad40[0x54 - 0x40];
    Opt_13f20 *opt;               // 0x54
};
namespace fn_fd8b7d01 {
struct Me_13f20 {
    char pad0[0x124];
    Player_13f20 *player;         // 0x124
};
struct Self_13f20 {
    char pad0[0x1c];
    Owner_13f20 *owner;           // 0x1c
    Cfg_13f20 *cfg;               // 0x20
    char pad24[0x34 - 0x24];
    int state;              // 0x34
    void FUN_00013f20(float k, Target_13f20 *t, float *outA, float *outB);
};


// 0x00013ec0 FUN_00013ec0 (15 B): matches/0x00013ec0.cpp
// sym: ?target@Obj_13ec0@fn_fd8b7d01@@QAEHXZ
hulk_intptr Obj_13ec0::target() {
    return ((C_13ec0 *)((owners::Object_592a0 *)member)->FUN_000592a0())->second_00059a30();
}


// 0x00013ed0 FUN_00013ed0 (74 B): matches/0x00013ed0.cpp
// sym: ?FUN_00013ed0@fn_fd8b7d01@@YI_NPAVA_13ed0@1@@Z
bool __fastcall FUN_00013ed0(A_13ed0* self) {
    C_13ed0* c = ((X_13ed0*)self->p1)->Fnf_000592a0();
    c = ((Y_13ed0*)c)->Fnf_00059a30();
    if (!c || !c->b || !c->b->flag) {
        D* d = (D*)self->p2;
        if (d->x > 0 && self->m34 >= d->x && d->y > 0 && self->m38 >= d->y)
            return true;
    }
    return false;
}


// 0x00013f20 FUN_00013f20 (712 B): equivalent/0x00013f20.cpp
// sym: ?FUN_00013f20@Self_13f20@fn_fd8b7d01@@QAEXMPAUTarget_13f20@2@PAM1@Z @96bf36e2a8cc @w943c2e8b84a8
// STATUS: equivalent (tools/equiv.py level 3: 20090 inputs, branch coverage 66/66)
// FUN_00013f20 @ 0x00013f20
void Self_13f20::FUN_00013f20(float k, Target_13f20 *t, float *outA, float *outB)
{
    World *g = DAT_004dd700;
    Me_13f20 *me = g->me;
    Player_13f20 *p = ((PlayerRef_13f20 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30();
    float r = ((owners::ClampOwner_3ebb0 *)p)->FUN_0003ebb0(1);
    *outB = r;
    float v = cfg->lo;
    *outA = v;
    float hi = cfg->hi;
    if (hi > 0.0f)
        *outA = v + (hi - v) * r;
    if (p->flag != 0 || cfg->forceMax != 0)
        *outB = 1.0f;
    *outA = k * *outA;
    int count = cfg->count;
    if (count > 0) {
        int f0, f1;
        if (((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0)) != 0) {
            int id = ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0))->id;
            f0 = ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0))->slot->FUN_001d5e80(id) == 1;
        } else {
            f0 = 0;
        }
        if (((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)1)) != 0) {
            int id = ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)1))->id;
            int r = ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)1))->slot->FUN_001d5e80(id);
            f1 = (r == 1) ? 1 : 0;
        } else {
            f1 = 0;
        }
        f1 <<= 1;
        int m = (f1 | f0) & count;
        if (m != 0) {
            *outA = *outA + *outA;
            *outB = 1.0f;
            if (state == 1) {
                if ((f0 & m) != 0 && ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0)) != 0)
                    ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0))->FUN_001d6ec0(4, p->val, 1);
                if ((f1 & m) != 0 && ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)1)) != 0)
                    ((Pad_13f20 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)1))->FUN_001d6ec0(4, p->val, 1);
            }
        }
    }
    {
        hulk_freg s = p->ctrl->scale;
        if (p->flag != 0)
            s = s * p->ctrl->mult;
        *outA = s * *outA;
    }
    if (t != 0) {
        int mode = cfg->mode;
        if (t->type == 1 && t->holder != 0 && t->holder->item != 0) {
            Item_13f20 *it = t->holder->item;
            if (it->dead == 0) {
                int kind = it->kind;
                bool ok = false;
                switch (mode) {
                case 1: ok = (kind == 0); break;
                case 2: ok = (kind == 1); break;
                case 3:
                case 4: ok = (kind == 2 || kind == 3); break;
                case 5:
                case 6: ok = (kind == 4); break;
                case 7:
                case 8: ok = (kind == 5); break;
                default: break;
                }
                if (ok) {
                    *outA = *outA + *outA;
                    const char *s = ((const char *)((owners::C_25890 *)me)->FUN_00025890(mode - 1));
                    if (s != 0 && *s != 0) {
                        int sink[2];
                        Text_13f20 *txt = g->hud->text;
                        int *r = ((int *)((owners::Palette_25930 *)me)->FUN_00025930((unsigned int *)sink, 1));
                        txt->FUN_000d4620(1, s, -1, *r, -1.0f);
                    }
                }
            }
        }
    }
    if (me->player == p) {
        if (((Flags_13f20 *)((owners::A_86340 *)(g->opt))->FUN_00086340())->FUN_00092940(0x2e1))
            *outA = 100000.0f;
    }
}

} // namespace fn_fd8b7d01

// 0x00014210 FUN_00014210 (533 B): equivalent/0x00014210.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00014210@fn_00014210@@YAXHPAUFrame_14210@1@PAXPAUVec3_14210@1@@Z @5aacbd1996e1 @waee3b7719c1f
namespace fn_00014210 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 12/12)
// FUN_00014210 @ 0x00014210

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


struct Vec3_14210 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Frame_14210 {
    void FUN_00035550(Vec3_14210 *out);
};

struct Probe_14210 {
    Vec3_14210 *FUN_001c39c0();
};

extern "C" void __cdecl FUN_00096a90(void *obj, Vec3_14210 *out);
extern "C" Probe_14210 *__cdecl FUN_001c3d90();

static float QuarterPi()
{
    return 0.78539818525f;
}

// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Frame_14210 *frame, void *obj, Vec3_14210 *out)
{
    if (mode == 2) {
        frame->FUN_00035550(out);
        out->y = 0.0f;
        out->FUN_0022d110();
        return;
    }

    if (mode == 1) {
        Vec3_14210 w;
        Vec3_14210 a;
        Vec3_14210 b;
        a.x = 0.0f;
        a.y = 0.0f;
        a.z = 0.0f;
        ((owners::Obj_35230 *)frame)->FUN_00035230((unsigned *)(Vec3_14210 *)(&a));
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        FUN_00096a90(obj, &b);
        out->y = 0.0f;
        out->x = b.x - a.x;
        out->z = b.z - a.z;
        out->FUN_0022d110();

        Probe_14210 *p = FUN_001c3d90();
        if (!p)
            return;

        Vec3_14210 *src = p->FUN_001c39c0();
        w.x = src->x;
        w.y = src->y;
        w.z = src->z;
        w.FUN_0022d110();
        w.x = w.x * 100.0f;
        w.y = w.y * 100.0f;
        w.z = w.z * 100.0f;
        Vec3_14210 *q = ((Vec3_14210 *)((owners::Object_1c39d0 *)p)->FUN_001c39d0());
        w.x = w.x + q->x;
        w.y = w.y + q->y;
        double z = w.z + q->z;
        w.y = 0.0f;
        w.x = w.x - b.x;
        w.z = (float)(z - b.z);
        w.FUN_0022d110();

        static float ang = QuarterPi();
        static float cs = (float)cos((double)(ang * 0.5f));
        if (w.z * out->z + w.y * out->y + w.x * out->x > cs) {
            out->x = w.x;
            out->y = w.y;
            out->z = w.z;
        }
        return;
    }

    Vec3_14210 a;
    Vec3_14210 b;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    ((owners::Obj_35230 *)frame)->FUN_00035230((unsigned *)(Vec3_14210 *)(&a));
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    FUN_00096a90(obj, &b);
    out->x = b.x - a.x;
    out->z = b.z - a.z;
    out->y = 0.0f;
    out->FUN_0022d110();
}
} // namespace fn_00014210


// 0x00014430 CCollisionAction::vfunc_7 (325 B): equivalent/0x00014430.cpp [wrapped: conflict: World]
// sym: ?vfunc_7@CCollisionAction@fn_00014430@@UAEDH@Z @dc984de90a06 @w169984497ae4
namespace fn_00014430 {
// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 11/12, incomplete; run with --inputs 12000)
// CCollisionAction::vfunc_7 @ 0x00014430
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

struct Vec3_14430 { float x, y, z; };

struct Mat_14430 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022c2b0(const Vec3_14430 *in, Vec3_14430 *out);
};

struct Anchor_14430 {
    Vec3_14430 *FUN_001d6b40();
};

struct Registry_14430 {
    Anchor_14430 *FUN_001dee40(int lo, int hi);
};

struct World {
    char pad0[0xc];
    Registry_14430 *registry;
};

struct Skeleton {
    char pad0[0x1c];
    Mat_14430 *matrices;
};

struct Body_14430 {
    char pad0[0x64];
    Skeleton *skeleton;
};

struct Fighter_14430 { char pad[4]; };
Fighter_14430 *__fastcall FUN_000592a0(void *owner);
extern "C" void *__fastcall FUN_00059a40(Fighter_14430 *f);
struct Stats_14430 {
    char pad[0x1d70];
    int idLo;
    int idHi;
};
extern "C" Stats_14430 *__fastcall FUN_00059a30(Fighter_14430 *f);

struct Resource_14430 {
    int lo;
    int hi;
};

struct Data_14430 {
    char pad0[0x20];
    Vec3_14430 offset;
    char pad2c[0x70 - 0x2c];
    Resource_14430 resource;
};

class Sink_14430 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_14430 *m, int arg);
};

class CCollisionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(int arg);
    virtual void vfunc_8();

    char pad04[0x18];
    void *owner;
    Data_14430 *data;
    int matrixIndex;
    char pad28[0x3c - 0x28];
    Sink_14430 *sink;
};

char CCollisionAction::vfunc_7(int arg)
{
    if (matrixIndex != 0)
        return 1;

    Fighter_14430 *fighter = FUN_000592a0(owner);
    Body_14430 *body = (Body_14430 *)FUN_00059a40(fighter);
    Stats_14430 *stats = FUN_00059a30(fighter);
    Mat_14430 *m = &body->skeleton->matrices[matrixIndex];

    Vec3_14430 pos;
    Resource_14430 *res = &data->resource;
    Anchor_14430 *anchor = 0;
    if (res && (res->lo | res->hi) != 0 && (stats->idLo | stats->idHi) != 0)
        anchor = DAT_004dd700->registry->FUN_001dee40(stats->idLo, stats->idHi);

    if (anchor) {
        pos = *anchor->FUN_001d6b40();
        Vec3_14430 off = data->offset;
        pos.x = off.x + pos.x;
        pos.y = off.y + pos.y;
        pos.z = off.z + pos.z;
    } else {
        Vec3_14430 off = data->offset;
        m->FUN_0022c2b0(&off, &pos);
    }

    if (sink) {
        Mat_14430 t;
        t.FUN_0022b980();
        t.m[12] = pos.x;
        t.m[13] = pos.y;
        t.m[14] = pos.z;
        sink->vfunc_6(&t, arg);
    }
    return 1;
}
} // namespace fn_00014430
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

